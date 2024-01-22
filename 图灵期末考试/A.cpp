#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
int n,m,dfsum,cnt,top;
unordered_map<int,bool>visi;
int c[N],head[N];
int stk[N],vis[N],du[N];
int sd[N],dfn[N],low[N];
int ans;
struct Edge{
    int u,v,nxt;
    Edge(){}
    Edge(int u,int v,int nxt):u(u),v(v),nxt(nxt){}
}edge[N];
void addedge(int x,int y){
    edge[++cnt]=Edge(x,y,head[x]);
    head[x]=cnt;
}
void tarjan(int u){
    stk[++top]=u;
    vis[u]=1;
    dfn[u]=low[u]=++dfsum;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]){
            low[u]=min(low[u],low[v]);
        }
    }
    if(dfn[u]==low[u]){
        int tmp;
        while(tmp=stk[top--]){
            sd[tmp]=u;
            vis[tmp]=0;
            if(tmp==u)  break;
            c[u]=min(c[tmp],c[u]);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }
    for(int i=1;i<=n;i++)   if(!dfn[i]) tarjan(i);
    for(int i=1;i<=m;i++){
        int u=sd[edge[i].u],v=sd[edge[i].v];
        if(u!=v)    du[v]++;
    }
    for(int i=1;i<=n;i++){
        if(du[sd[i]]==0&&!visi[sd[i]]){
            ans+=c[sd[i]];
            visi[sd[i]]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}