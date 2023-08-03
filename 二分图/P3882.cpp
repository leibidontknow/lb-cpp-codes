#include<bits/stdc++.h>
using namespace std;
int x,y;
vector<int>G[5000];
bool vis[5000];
int a[5000][5000];
bool putdj1[5000];
bool putdj2[5000];
bool putx[2000];
bool puty[2000];
bool puttu[2000][2000];
int mp[2000][2000];
int dx[2000];
bool dfs(int u){
    for(int v:G[u]){
        if(vis[v])   continue;
        vis[v]=1;
        if(!dx[v]||dfs(dx[v])){
            dx[v]=u;
            return true;
        }
    }
    return false;
}
bool check(int x,int y){
    if(putdj1[y-x+2000]) return true;
    if(putdj2[y+x+2000]) return true;
    if(putx[x]||puty[y])    return true;
    if(puttu[x][y]) return true;
    return false;
}
char str[2048];
int main(){
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        cin>>(str+1);
        for(int j=1;j<=y;j++){
            char ch;
            ch=str[j];
            if(ch!='.'){
                putdj1[j-i+2000]=1;
                putdj2[j+i+2000]=1;
                if(ch=='K'){
                    puttu[i+1][j]=1;
                    puttu[i-1][j]=1;
                    puttu[i][j+1]=1;
                    puttu[i][j-1]=1;
                }
                if(ch=='Q'||ch=='R'){
                    putx[i]=1;
                    puty[j]=1;
                }
                if(ch=='N'){
                    if(j-2>=0){
                        puttu[i+1][j-2]=1;
                        puttu[i-1][j-2]=1;
                    }
                    if(i-2>=0){
                        puttu[i-2][j+1]=1;
                        puttu[i-2][j-1]=1;
                    }
                    puttu[i+2][j-1]=1;
                    puttu[i+2][j+1]=1;
                    puttu[i-1][j+2]=1;
                    puttu[i+1][j+2]=1;
                }
                if(ch=='P'){
                    puttu[i+1][j-1]=1;
                    puttu[i+1][j+1]=1;
                }
            }
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(!check(i,j)){
                mp[i][j]=1;
            }
            else{
                mp[i][j]=2;
            }
            // cout<<mp[i][j];
        }
        // cout<<endl;

    }
    for(int i=1;i<=x;i++){
        int n,m;
        m=x-i+1;
        n=i;
        for(int j=1;j<=y;j++){
            a[n++][m++]=mp[i][j];
        }
    }
    for(int i=1;i<=x+y-1;i++){
        for(int j=1;j<=x+y-1;j++){
            if(a[i][j]&1)   G[i].push_back(j);
        }
    }
    int ans=0;
    for(int i=1;i<=x+y-1;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))  ans++;
    }
    cout<<ans<<endl;
    return 0;
}