#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int to[N],head[N],cnt,nxt[N];
int dfn[N],dfn_sum,low[N],col[N],col_num[N],st[N],top,inst[N],num,out[N];
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void dfs(int u){
    dfn[u]=low[u]=++dfn_sum;
    st[++top]=u;
    inst[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(!dfn[v]){
            dfs(v);
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=nxt[j]){
            int v=to[j];
            if(col[v]!=col[i]){
                out[col[i]]++;
            }
        }
    }
    int ans=0,flag=0;
    for(int i=1;i<=num;i++){
        if(!out[i]) ans=col_num[i],flag++;
    }
    if(flag!=1) return cout<<0<<endl,0;
    cout<<ans<<endl;
    return 0;
}