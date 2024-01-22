#include<bits/stdc++.h>
using namespace std;
int dx[1919810],vis[1919810],ans;
vector<int>G[1919810];
int n,m;
int nox,noy;
unordered_map<string,int>mp;
int cnt;
bool dfs(int u,int k){
    for(int v:G[u]){
        if(vis[v]==k||(u==nox&&v==noy))   continue;
        vis[v]=k;
        if(!dx[v]||dfs(dx[v],k)){
            return true;
        }
    }
    return false;
}
int bhx,bhy;
vector<int>vec;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        bhx=mp[x]=++cnt;
        bhy=mp[y]=++cnt;
        dx[bhx]=bhy;
        dx[bhy]=bhx;
        vec.push_back(bhx);
        G[bhx].push_back(bhy);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string x,y;
        cin>>x>>y;
        int bhx=mp[x],bhy=mp[y];
        G[bhx].push_back(bhy);
    }
    for(int i:vec){
        nox=i;
        noy=dx[i];
        dx[noy]=0;
        if(dfs(i,i))    puts("Unsafe");
        else puts("Safe");
        dx[noy]=1;
    }
    return 0;
}