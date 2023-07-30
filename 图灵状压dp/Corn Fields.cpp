#include<bits/stdc++.h>
using namespace std;
const int mod=1e8;
int n,m,ans;
int mp[20];
int dp[20][200000];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp;
            cin>>tmp;
            mp[i]=mp[i]<<1;
            mp[i]+=tmp;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int pre=0;pre<(1<<m);pre++){
            if(dp[i][pre]){
                for(int s=mp[i+1];;s=(s-1)&mp[i+1]){
                    if((s&(s>>1))==0&&(s&pre)==0){
                        dp[i+1][s]+=dp[i][pre];
                        dp[i+1][s]%=mod;
                    }
                    if(s==0)    break;
                }
            }
        }
    }
    for(int s=0;s<(1<<m);s++){
        ans+=dp[n][s];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}