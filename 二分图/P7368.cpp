#include<bits/stdc++.h>
using namespace std;
int dx[1919810],vis[1919810],ans;
vector<int>G[1919810];
int n,m,e;
bool dfs(int u,int k){
    for(int v:G[u]){
        if(vis[v]==k)   continue;
        vis[v]=k;
        if(!dx[v]||dfs(dx[v],k)){
            dx[v]=u;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y+n);
        G[y+n].push_back(x);
    }
    for(int i=1;i<=n;i++){
        ans+=dfs(i,i);
    }
    cout<<ans<<endl;
    return 0;
}