/*****************************************
备注：
******************************************/
#include <queue>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include <algorithm>
using namespace std;
#define LL long long
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n , d , T , x[N] , y[N];
char a[N] , c1[N] , c2[N];
int ff[N];
int head[N] , to[N] , ne[N] , id;
int dfn[N] , low[N] , col[N] , cnt , st[N] , top , num , vis[N];
int flag = 1;
 void init()
{
	id = num = top = cnt = 0;
	memset(head , 0 , sizeof(head));
	memset(dfn , 0 , sizeof(dfn));
	memset(low , 0 , sizeof(low));
}
 void add(int x, int y)
{
	id++;
	to[id] = y  , ne[id] = head[x] , head[x] = id;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++num;
	st[++top] = u;
	vis[u] = 1;
	for(int i = head[u] ; i ; i = ne[i])
	{
		int v = to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[v] , low[u]);
		}
		else if(vis[v])
			low[u] = min(low[u] , dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		++cnt;
		int s;
		do
		{
			s = st[top--];
			col[s] = cnt;
			vis[s] = 0;

		}while(low[s] != dfn[s]);
	}
}
 int get(int idx , char ss)
{
	if(a[idx] == 'a')
		return ss == 'B' ? idx : idx + n;
	if(a[idx] == 'b' || a[idx] == 'c')
		return ss == 'A' ? idx : idx + n;
}
int rev(int idx)
{
	return idx <= n ? idx + n : idx - n;
}
 void build()
{
	init();
	for(int i = 1 ;i <= T ; i++)
	{
		int t1  = x[i] , t2 = y[i];
		int is1 = get(t1,c1[i]) , is2 = get(t2,c2[i]);
		if(a[t1] - 32 == c1[i]) 
			continue;
		if(a[t2] - 32 == c2[i])
		{
			add(is1 , rev(is1)); // ?
			continue;
		}
		add(is1 , is2);
		add(rev(is2) , rev(is1));
	}
}
void dfs(int step)
{
	if(step > d)
	{
		build();
		for(int i = 1; i <= 2*n ; i++)
			if(!dfn[i])
				tarjan(i);
		for(int i = 1 ;i <= n ; i++)
			if(col[i] == col[i+n])
				return;
		flag = 0;
		return;
	}
	for(int i = 0 ; i <= 1 ; i++)
	{
		a[ff[step]] = i + 'a';
		dfs(step + 1);
		if(!flag)
			return ;
	}
}
int main()
{
	scanf("%d%d",&n,&d);
	scanf("%s",a+1);
	scanf("%d",&T);
	for(int i = 1; i <= T ; i++)
		scanf("%d %c %d %c",&x[i],&c1[i],&y[i],&c2[i]);

	int ss = 1;
	for(int i = 1 ;i <= n ; i++)
		if(a[i] == 'x')
			ff[ss++] = i;
	dfs(1);
	if(flag)
		cout << -1;
	else 
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(a[i] == 'a')
				printf("%c",col[i] < col[i+n] ? 'B' : 'C');
			if(a[i] == 'b')
				printf("%c",col[i] < col[i+n] ? 'A' : 'C');
			if(a[i] == 'c')
				printf("%c",col[i] < col[i+n] ? 'A' : 'B');
		}
	}


	return 0;
}
