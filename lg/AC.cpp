/*************************************************************************
	> File Name: AC.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int MAXN = 2e5 + 10;
const int MR = 10 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;			
const int _ = 0;
const bool debug = false;

int n, m;
int head[MAXN],to[MAXN], ne[MAXN], id;
int siz[MAXN], dep[MAXN], fa[MAXN][MR];
void add(int x, int y)
{
	to[++id] = y;
	ne[id] = head[x];
	head[x] = id;
}
void dfs(int u, int f)
{
	siz[u] = 1;
	dep[u] = dep[f]+ 1;
	fa[u][0] = f;
	for(int i = 1; i <= 13; i++)
	{
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	for(int i = head[u]; i; i = ne[i])
	{
		int v = to[i];
		if(v == f) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void calc(int x, int y)
{
	if(x == y)
	{
		cout << siz[1] << endl;
		return ;
	}
	if(dep[x] == dep[y])
	{
		for(int i = 14; i >= 0; i--)
		{
			if(fa[x][i] != fa[y][i])
			{
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		cout << siz[1] - siz[x] - siz[y] << endl;
		return ;
	}
	if(dep[x] < dep[y])swap(x, y);
	if((dep[x] - dep[y]) % 2 == 1)
	{
		puts("0");
		return ;
	}
	int tmp = x;
	int DEP = (dep[x] - dep[y]) / 2;
	for(int i = 13; i >= 0; i--)
	{
		if(dep[fa[x][i]] >= dep[y])
		{
			x = fa[x][i];
		}
	}
	if(x == y)
	{
		DEP += dep[x];
		for(int i = 13; i >= 0; i--)
		{
			if(dep[fa[tmp][i]] > DEP)
			{
			    tmp = fa[tmp][i];
			}
		}
		cout << siz[fa[tmp][0]]-siz[tmp] << endl;
		return;
	}
	for(int i = 13; i >= 0; i--)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	DEP += dep[x] - 1; 
	for(int i = 13; i >= 0; i--)
	{
		if(dep[fa[tmp][i]] > DEP) 
		{
			tmp=fa[tmp][i];
		}
	}
	cout << siz[fa[tmp][0]]-siz[tmp] << endl;
}
signed main()
{
	// int start = clock();
	cin >> n;
	for(int i = 1, x, y; i < n; i++)
	{
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	cin >> m;
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		calc(x, y);
	}
	// printf("%.3lf", clock() - start);
    return 0;
}
