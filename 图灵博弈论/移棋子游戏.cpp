#include<bits/stdc++.h>
using namespace std;
int n,a[1919810],m,k;
int xorsum;
int dp[1919810];
vector<int>G[19190];
int dfs(int x){
    if(dp[x]!=-1)   return dp[x];
    vector<bool>vis(n);
    for(int v:G[x]){
        vis[dfs(v)]=1;
    }
    for(int j=0;;j++){
        if(!vis[j]){
            dp[x]=j;
            break;
        }
    }
    return dp[x];
}
int main(){
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=k;i++){
        cin>>a[i];
        xorsum^=dfs(a[i]);
    }
    if(xorsum==0){
        cout<<"lose"<<endl;
    }
    else{
        cout<<"win"<<endl;
    }
    return 0;
}