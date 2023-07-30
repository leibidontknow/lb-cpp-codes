#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define max(a,b)    [](int c,int d){return c>d?c:d;}(a,b)
#define min(a,b)    [](int c,int d){return c<d?c:d;}(a,b)
int n,dp[1919810][2];
int degree[1919810];
int rot;
vector<int>vec[7000];
int dfs(int now){
    for(int v:vec[now]){
        dfs(v);
        dp[now][0]+=dp[v][1];
        dp[now][1]+=min(dp[v][0],dp[v][1]);
    }
    return min(dp[now][0],dp[now][1]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        int noww;
        cin>>noww;
        noww++;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v;
            cin>>v;
            v++;
            vec[noww].push_back(v);
            degree[v]++;
        }
    }
    for(int i=1;i<=n;i++)   if(degree[i]==0)    rot=i;
    cout<<dfs(rot)<<endl;
    return 0;
}