#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int to[N],head[N],cnt,nxt[N];
int dfn[N],dfn_sum,low[N],col[N],col_num[N],st[N],top,inst[N],num,du[N];
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa){
    dfn[u]=low[u]=++dfn_sum;
    st[++top]=u;
    inst[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(v==fa)   continue;
        if(!dfn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v]) low[u]=min(low[u],dfn[v]);
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
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            dfs(i,0);
        }
    }
    return 0;
}