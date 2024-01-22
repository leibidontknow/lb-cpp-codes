#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r,x;
int solve(int n){
    int dp[300][2][10];
    int d[300];
    int len=0;
    memset(dp,0,sizeof(dp));
    memset(d,0,sizeof(d));
    do{
        d[len++]=n%10;
        n/=10;
    }while(n);
    dp[len][1][0]=1;
    for(int i=len;i>0;i--){
        for(int c=0;c<=9;c++){
            if(c==x)    continue;
            for(int k=0;k<x;k++)    dp[i-1][0][(k*10+c)%x]+=dp[i][0][k];
            if(c>d[i-1])    continue;
            if(c==d[i-1]){
                for(int k=0;k<x;k++)    dp[i-1][1][(k*10+c)%x]+=dp[i][1][k];
            }
            else{
                for(int k=0;k<x;k++)    dp[i-1][0][(k*10+c)%x]+=dp[i][1][k];
            }
        }
    }
    int ans=0;
    for(int i=1;i<x;i++)    ans+=dp[0][0][i]+dp[0][1][i];
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>l>>r>>x;
    cout<<solve(r)-solve(l-1)<<endl;
    return 0;
}