#include<bits/stdc++.h>
using namespace std;
const int N =5100;
int n,m;
int a[N][N],r[N][N],c[N][N],dx[N],vis[N],lenr=1,lenc=1,ans;
int maxx=0;
vector<int>G[N];
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
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='x'){
                a[i][j]=-2;
            }
            if(ch=='#'){
                a[i][j]=-1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!a[i][j])    r[i][j]=lenr;
            if(a[i][j]==-1)    lenr++;
        }
        lenr++;
    }
    maxx=max(lenr,maxx);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!a[j][i])    c[j][i]=lenc;
            if(a[j][i]==-1)    lenc++;
        }
        lenc++;
    }
    maxx=max(lenc,maxx);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!a[i][j]){
                G[r[i][j]].push_back(c[i][j]);
            }
        }
    }
    for(int i=1;i<maxx;i++){
        ans+=dfs(i,i);
    }
    cout<<ans<<endl;
    return 0;
}