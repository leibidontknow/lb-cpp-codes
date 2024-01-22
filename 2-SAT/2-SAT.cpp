/*************************************************************************
	> File Name: 2-SAT.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月06日 星期日 20时54分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
int n,m;
int head[N], to[N], nxt[N];
void add(int x, int y){
	static int cnt=0;
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int dfn[N],col[N],cnt,low[N],st[N],top,inst[N],num,col_num[N];
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	st[++top] = u;
	inst[u] = 1;
	for(int i = head[u];i;i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(inst[v]){
			low[u] = min(dfn[v], low[u]);
		}
	}
    if(low[u]==dfn[u]){
        num++;
        while(1){
            int tmp=st[top--];
            inst[tmp]=0;
            col[tmp]=num;
            col_num[num]++;
            if(tmp==u)  break;
        }
    }
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y,f1,f2;i<=m;i++){
		cin>>x>>f1>>y>>f2;
		add(x+n*(f1^1),y+f2*n);
		add(y+n*(f2^1),x+f1*n);
	}
	for(int i=1;i<=2*n;i++){
		if(!dfn[i])
			tarjan(i);
	}
	int flag=0;
	for(int i = 1;!flag&&i <= n;i++)
		if(col[i]==col[i+n])	flag=1;
	if(flag){
		puts("IMPOSSIBLE");
	}
	else{
		puts("POSSIBLE");
		for(int i=1;i<=n;i++)	cout<<(col[i]>col[i+n])<<' ';
	}
	cout<<endl;
	return 0;
}
