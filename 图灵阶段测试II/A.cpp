/*************************************************************************
  > File Name: A.cpp
  > Author: lbdontknow
  > Mail: lbdontknow@163.com 
  > Created Time: 2023年08月06日 星期日 10时00分02秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1919810],b[1919810];
int c(int i,int j){
	return a[i]^b[j];
}
int dp[5010][5010],q1[5010],q1l,q1r,q2[5010],q2l,q2r;
int l,r;
signed main(){   
	ios::sync_with_stdio(false);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)	dp[1][i]=c(1,i);
	for(int i=2;i<=n;i++){
		q1l=q1r=q2l=q2r=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(abs(j-k)>=l&&abs(j-k)<=r){
					dp[i][j]=max(dp[i][j],dp[i-1][k]+c(i,j));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[n][1]=max(dp[n][i],dp[n][1]);
	}
	cout<<dp[n][1]<<endl;
	return 0;
}
