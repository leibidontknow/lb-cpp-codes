/*************************************************************************
	> File Name: 2-SAT.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月06日 星期日 20时54分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 4e3 + 10;
int n,m;
int head[N], to[N], nxt[N];
void add(int x=-1, int y=-1){
	static int cnt=0;
	//cout<<cnt<<endl;
	if(x==-1&&y==-1){
		cnt=0;
		return;
	}
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
int T;
int main(){
	cin>>T;
	while(T--){
		memset(to, 0, sizeof(to));
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(col, 0, sizeof(col));
		memset(col_num, 0, sizeof(col_num));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(inst, 0, sizeof(inst));
		memset(st,0,sizeof(st));
		cnt=num=0;
		add();
		top=0;
		cin >> n >> m;
		for(int i=1,x,y,f1,f2;i<=m;i++){
			string s,ss;
			cin>>s>>ss;
			x=s[1]-'0';
			y=ss[1]-'0';
			for(int j=2;j<s.length();j++){
				x=x*10+s[j]-'0';
			}
			for(int j=2;j<ss.length();j++){
				y=y*10+ss[j]-'0';
			}
			f1=(s[0]=='h'?0:1);
			f2=(ss[0]=='h'?0:1);
			//cin>>x>>f1>>y>>f2;
			add(x+n*(f1^1),y+f2*n);
			add(y+n*(f2^1),x+f1*n);
		}
		for(int i=1;i<=2*n;i++){
			if(!dfn[i])
				tarjan(i);
		}
		int flag=0;
		for(int i = 1;!flag&&i <= n;i++)
			if(col[i] == col[i+n])	flag=1;
		if(flag){
			puts("BAD");
		}
		else{
			puts("GOOD");
		}
		//cout<<endl;
	}
	return 0;
}
