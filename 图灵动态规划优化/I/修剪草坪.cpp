#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int sum[1919810],ds[1919810];
int q[1919810],l,r;
int dp[1919810];
int ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    l=r=1;
    q[r++]=0;
    for(int i=1;i<=n;i++){
        ds[i]=dp[i-1]-sum[i];
        while(l<r&&ds[q[r-1]]<ds[i])    r--;
        q[r++]=i;
        while(l<r&&q[l]<i-k)    l++;
        dp[i]=ds[q[l]]+sum[i];
    }
    cout<<dp[n]<<endl;
    return 0;
}