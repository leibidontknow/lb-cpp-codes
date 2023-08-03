#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[1919810],sum[1919810],a[1919810],q[1919810],l,r;
int X(int x){
    return sum[x];
}
int Y(int j){
    return dp[j]+sum[j]*sum[j];
}
long double slope(int j1,int j2){
    return (long double)(Y(j2)-Y(j1))/(X(j2)-X(j1));
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    l=r=0;
    q[r++]=0;
    for(int i=1;i<=n;i++){
        while(l+1<r&&slope(q[l],q[l+1])<=2*sum[i])  l++;
        dp[i]=dp[q[l]]+(sum[i]-sum[q[l]])*(sum[i]-sum[q[l]])+m;
        while(l+1<r&&slope(q[r-2],q[r-1])>=slope(q[r-1],i)) r--;
        q[r++]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}