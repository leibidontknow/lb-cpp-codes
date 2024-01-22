#include<bits/stdc++.h>
using namespace std;
#define min(a,b)    [](int c,int d){return c<d?c:d;}(a,b)
int dp[200000][20],n;
int mp[200][200];
int main(){
    memset(mp,0x3f,sizeof(mp));
    cin>>n;
    for(int i=1;i<=n*(n+1);i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=w;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int s=2;s<(1<<(n+1));s++){
        for(int i=0;i<=n;i++){
            if(s&(1<<i)){
                int pres=s^(1<<i);
                for(int j=0;j<=n;j++){
                    if(pres&(1<<j)){
                        dp[s][i]=min(dp[s][i],dp[pres][j]+mp[j][i]);
                    }
                }
            }
        }
    }
    int minn=INT_MAX;
    for(int i=1;i<=n;i++){
        minn=min(minn,dp[(1<<(n+1))-1][i]+mp[i][0]);
    }
    cout<<minn<<endl;
    return 0;
}