/*************************************************************************
	> File Name: J.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int b[20], W, n;
int a[50010];
int dp[50000];
int dp2[50000];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> W;
	memset(dp, 0x3f, sizeof(dp));
	memset(dp2, 0x3f, sizeof(dp2));
	dp[0] = 1;
	dp2[0] = 0;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i], b[a[i]]++;
	for(int l = 1 ; l <= 13 ; l++)
	for(int i = 1 ; i <= 13 ; i++){		
		for(int k = 0 ; k < (1 << 13) ; k++){
			if(k & (1 << (i - 1)))	continue;
			if(dp2[k] + b[i] <= W){
				if(dp[k] < dp[k | (1 << (i - 1))]){
					dp[k | (1 << (i - 1))] = dp[k];
					dp2[k | (1 << (i - 1))] = dp2[k] + b[i];
				}
				else if(dp[k] == dp[k | (1 << (i - 1))]){
					dp2[k | (1 << (i - 1))] = min(dp2[k | (1 << (i - 1))], dp2[k] + b[i]);
				}
			}
			else{
				if(dp[k] + 1 <= dp[k | (1 << (i - 1))]){
					dp[k | (1 << (i - 1))] = dp[k] + 1;
					dp2[k | (1 << (i - 1))] = b[i];
				}
			}
		}
	}
	cout << dp[(1 << 13) - 1] << endl;
	return 0;
}
