#include<bits/stdc++.h>
using namespace std;
int r,c,ans;
int cnth,s[1000],cnts,vis[100010],num[100010],h[1000];
int _map[1000][1000];
bool dfs(int id){
    for(int i=1;i<=cnts;i++){
        if(vis[i]||_map[id][i]==0){continue;}
        vis[i]=1;
        if(num[i]==-1||dfs(num[i])==1){
            num[i]=id;
            return 1;
        }
    }
}
int main(){
    memset(num,-1,sizeof(num));
    cin>>r>>c;
    cnts=c,cnth=r;
    for(int i=1;i<=c;i++)   s[i]=i;
    for(int i=1;i<=r;i++)   h[i]=i;
    for(int i=1;i<=r;i++){
        string ss;
        cin>>ss;
        for(int j=1;j<=c;j++){
            char ch=ss[j-1];
            if(ch=='*') _map[h[i]][s[j]]=1;
            else{
                h[i]=++cnth;
                s[j]=++cnts;
            }
        }
    }
    for(int i=1;i<=cnth;i++){
        for(int j=1;j<=cnts;j++)    cout<<_map[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}