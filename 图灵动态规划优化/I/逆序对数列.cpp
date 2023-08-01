#include<bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int n,k;
int sum[2000][2000];
const int mod=10000;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    dp[1][0]=1;
    for(int i=0;i<=k;i++)   sum[1][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=sum[i-1][j];
            if(j-i>=0)  dp[i][j]=(dp[i][j]-sum[i-1][j-i])%mod;
        }
        sum[i][0]=dp[i][0];
        for(int j=1;j<=k;j++){
            sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
        }
    }
    cout<<(dp[n][k]+mod)%mod<<endl;
    return 0;
}