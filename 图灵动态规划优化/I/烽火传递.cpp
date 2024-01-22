#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m; 
int dp[1919810],ans=LLONG_MAX;
int a[1919810],q[1919810],l,r;
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)    scanf("%lld",&a[i]);
    l=r=1;
    q[r++]=0;
    for(int i=1;i<=n;i++){
        while(l<r&&q[l]<i-m)  l++;
        dp[i]=a[i]+dp[q[l]];
        if(i>n-m)    ans=min(ans,dp[i]);
        while(l<r&&dp[q[r-1]]>dp[i])  r--;
        q[r++]=i;
    }
    cout<<ans<<endl;
    return 0;
}