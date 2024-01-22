#include<bits/stdc++.h>
using namespace std;
int t,maxp,w;
int dp[2010][2010];
int q[1919810];
int l,r;
int ans=INT_MIN;
int main(){
    ios::sync_with_stdio(false);
    memset(dp,0xcf,sizeof(dp));
    dp[0][0]=0;
    cin>>t>>maxp>>w;
    for(int i=1;i<=t;i++){
        register int ap,bp,as,bs;
        cin>>ap>>bp>>as>>bs;
        for(int j=0;j<=as;j++)  dp[i][j]=-j*ap;
        for(int j=0;j<=maxp;j++)  dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(i<=w)    continue;
        l=r=1;
        for(int j=0;j<=maxp;j++){
            while(l<r&&q[l]<j-as)   l++;
            while(l<r&&dp[i-w-1][q[r-1]]+q[r-1]*ap<dp[i-w-1][j]+j*ap)   r--;
            q[r++]=j;
            if(l<r) dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]-(j-q[l])*ap);
        }
        l=r=1;
        for(int j=maxp;j>=0;j--){
            while(l<r&&q[l]>j+bs)   l++;
            while(l<r&&dp[i-w-1][q[r-1]]+q[r-1]*bp<dp[i-w-1][j]+j*bp)   r--;
            q[r++]=j;
            if(l<r) dp[i][j]=max(dp[i][j],dp[i-w-1][q[l]]+(q[l]-j)*bp);
        }
    }
    for(int i=0;i<=maxp;i++)    ans=max(ans,dp[t][i]);
    cout<<ans<<endl;
    return 0;
}