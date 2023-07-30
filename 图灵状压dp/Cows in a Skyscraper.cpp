#include<bits/stdc++.h>
using namespace std;
int n,w,c[19191810],dp[1000000],flag[1000000];
int main(){
    memset(dp,0x3f,sizeof(dp));
    ios::sync_with_stdio(false);
    cin>>n>>w;
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int s=1;s<(1<<n);s++){
        flag[s]=1;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(s&(1<<(i-1))){
                sum+=c[i];
                if(sum>w){
                    flag[s]=0;
                    break;
                }
            }
        }
    }
    dp[0]=0;
    for(int s=1;s<(1<<n);s++){
        for(int ss=s;ss;ss=((ss-1)&s)){
            if(flag[ss]){
                dp[s]=min(dp[s],dp[s^ss]+1);
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}