#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[200];
int dp[3][1024][1024];
int sum[1024];
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin>>tmp;
            int tmpp;
            tmpp=(tmp=='H'?1:0);
            mp[i]=(mp[i]<<1)+tmpp;
        }
    }
    for(int i=0;i<(1<<m);i++){
        int tmp=i;
        while(tmp){
            sum[i]+=(tmp&1);
            tmp>>=1;
        }
        if((i&mp[0])==0&&(i&(i<<1))==0&&(i&(i<<2))==0){
            dp[0][0][i]=sum[i];
        }
    }
    for(int s1=0;s1<(1<<m);s1++){
        for(int s2=0;s2<(1<<m);s2++){
            if( (s1&s2)==0 && (s1&mp[0])==0 && (s2&mp[1])==0 && (s1&(s1>>1))==0 && (s2&(s2>>1))==0 && (s1&(s1>>2))==0 && (s2&(s2>>2))==0)   {
                dp[1][s1][s2]=sum[s1]+sum[s2];
            }                                         
        }
    }
    for(int i=2;i<n;i++){
        for(int s1=0;s1<(1<<m);s1++){
            if((s1&(s1>>1))||(s1&(s1>>2))||(s1&mp[i-1])){
                continue;
            }

            for(int s2=0;s2<(1<<m);s2++){
                if((s2&(s2>>1))||(s2&(s2>>2))||(s2&mp[i])){
                    continue;
                }
                
                for(int s0=0;s0<(1<<m);s0++){
                    if((s0&s1)||(s0&s2)||(s0&mp[i-2])||(s0&(s0>>1))||(s0&(s0>>2))){
                        continue;
                    }
                    dp[i%3][s1][s2]=max(dp[i%3][s1][s2],dp[(i-1)%3][s0][s1]+sum[s2]);
                }
            }
        }
    }
    for(int s1=0;s1<(1<<m);s1++){
        for(int s2=0;s2<(1<<m);s2++){
            ans=max(ans,dp[(n-1)%3][s1][s2]);
        }
    }
    cout<<ans<<endl;
    return 0;
}