#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1919810],q[1919810],r;
int dp[1919810],sum[1919810];
inline int Y(int j){
    return sum[j]*(j+1)-dp[j];
}
inline int X(int j){
    return j;
}
inline long double slope(int j1,int j2){
    return (long double)(Y(j2)-Y(j1))/(X(j2)-X(j1));
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i],sum[i]=sum[i-1]+a[i];
    dp[0]=0;
    r=0;
    q[r++]=0;
    for(int i=1;i<=n;i++){
        int le=0,ri=r-2,mid,pos=r-1;
        while(le<=ri){
            mid=le+ri>>1;
            if(slope(q[mid],q[mid+1])<sum[i]){
                pos=q[mid+1];
                le=mid+1;
            }
            else{
                pos=q[mid];
                ri=mid-1;
            }
            dp[i]=dp[pos]+(sum[i]-sum[pos])*(pos+1)-m;
            while(1<r&&slope(q[r-2],q[r-1])>=slope(q[r-1],i))   r--;
            q[r++]=i;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}