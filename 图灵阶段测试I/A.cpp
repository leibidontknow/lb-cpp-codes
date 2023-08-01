#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int n;
struct edge{
    int v,w;
    edge(){}
    edge(int v,int w):v(v),w(w){}
};
int a[1919810];
int dp[1919810];
// int vis[19199810];
vector<edge>G[1919810];
int dfs(int x,int fa){
    if(dp[x]!=inf){
        for(edge e:G[x]){
            dp[x]=min(dp[x],dp[e.v]+2*e.w);
        }
        return dp[x];
    }
    int ans=a[x];
    for(edge e:G[x]){
        int v=e.v;
        int w=e.w;
        if(v==fa)   continue;
        ans=min(ans,dfs(v,x)+2*w);
    }
    dp[x]=ans;
    for(edge e:G[x]){
        int v=e.v;
        int w=e.w;
        if(v==fa)   continue;
        dp[v]=min(dp[v],dp[x]+2*w);
    }
    return dp[x];
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(edge(v,w));
        G[v].push_back(edge(u,w));
    }
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cout<<dfs(i,0)<<' ';
    return 0;
}