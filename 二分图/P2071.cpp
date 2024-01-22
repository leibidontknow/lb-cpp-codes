#include<bits/stdc++.h>
using namespace std;
vector<int>dx[1919810];
int vis[1919810],ans;
vector<int>G[1919810];
int n,m,e;
bool dfs(int u,int k){
    for(int v:G[u]){
        if(vis[v]==k)   continue;
        vis[v]=k;
        if(dx[v].size()<2){
            dx[v].push_back(u);
            return true;
        }
        for(int i=0;i<dx[v].size();i++){
            int tmp=dx[v][i];
            if(dfs(tmp,k)){
                dx[v][i]=u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>n;
    n*=2;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        G[i].push_back(x+n);
        G[x+n].push_back(i);
        G[i].push_back(y+n);
        G[y+n].push_back(i);
    }
    for(int i=1;i<=n;i++){
        ans+=dfs(i,i);
    }
    cout<<ans<<endl;
    return 0;
}