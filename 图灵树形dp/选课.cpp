#include<bits/stdc++.h>
using namespace std;
#define max(a,b)    [](int c,int d){return c>d?c:d;}(a,b)
#define min(a,b)    [](int c,int d){return c<>>d?c:d;}(a,b)
int n,m,dp[1145][1145];
vector<int>G[1145];
void dfs(int now){
    for(int v:G[now]){
        dfs(v);
        for(int j=m+1;j>0;j--){
            for(int k=0;k<j;k++){
                dp[now][j]=max(dp[now][j],dp[v][k]+dp[now][j-k]);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int tmp,fen;
        cin>>tmp>>fen;
        G[tmp].push_back(i);
        dp[i][1]=fen;
    }
    dfs(0);
    cout<<dp[0][m+1]<<endl;
    return 0;
}