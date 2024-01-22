#include<bits/stdc++.h>
using namespace std;
int dx[1919810],vis[1919810],ans;
vector<int>G[1919810];
struct line{
    int x,y,xx,yy;
    int hs;
}l[1919810];
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
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        if(x==xx){
            l[i].hs=2;
        }
        else{
            l[i].hs=1;
        }
        l[i].x=x,l[i].y=y,l[i].xx=xx,l[i].yy=yy;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(l[i].hs==1&&l[j].hs==2){
                G[i].push_back(j+n);
                G[j+n].push_back(i+n);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=dfs(i,i);
    }
    cout<<n-ans<<endl;
    return 0;
}