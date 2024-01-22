#include<bits/stdc++.h>
using namespace std;
int n,m,dp[1919810],a[5919810];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)   cin>>a[i];
    dp[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++)   dp[i+a[j]]|=!(dp[i]);
    }
    cout<<(dp[n]==1?"Alice":"Bob")<<endl;
    return 0;
}