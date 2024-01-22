/*************************************************************************
	> File Name: G.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long 
int T, n, a[200000 + 10];
int dp[200000 + 10][3], l[200000 + 10][3], r[200000 + 10][3], sum[200000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		sum[0] = 1;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
			dp[i][1] = dp[i][2] = dp[i][3] = 0;
			l[i][1] = l[i][2] = l[i][3] = 1;
			r[i][1] = r[i][2] = r[i][3] = 0;
			sum[i] = sum[i - 1] * a[i];
		}
		l[0][1] = l[0][2] = l[0][3] = 1;
		for(int i = 1 ; i <= n ; i++){
			dp[i][0] = dp[i - 1][0] + a[i];

			if(dp[i - 1][0] + a[i] > dp[l[i - 1][1] - 1][0] + sum[i - 1] / sum[l[i - 1][1] - 1] * a[i]){
				l[i][1] = i;
				dp[i][1] = dp[i - 1][0] + a[i];
			}
			else{
				dp[i][1] = dp[l[i - 1][1] - 1][0] + sum[i - 1] / sum[l[i - 1][1] - 1] * a[i];
				l[i][1] = l[i - 1][1];
			}
			
			if(dp[l[i - 1][1] - 1][0] + sum[i - 1] / sum[l[i - 1][1] - 1] * a[i] > dp[i - 1][2] + a[i]){
				dp[i][2] = dp[l[i - 1][1] - 1][0] + sum[i - 1] / sum[l[i - 1][1] - 1] * a[i];
				r[i][2] = i;
				l[i][2] = l[i - 1][1];
			}
			else{
				dp[i][2] = dp[i - 1][2] + a[i];
				l[i][2] = l[i - 1][2];
				r[i][2] = r[i - 1][2];
			}
		}
		cout << l[n][2] << ' ' << r[n][2] << endl;
	}
	return 0;
}
