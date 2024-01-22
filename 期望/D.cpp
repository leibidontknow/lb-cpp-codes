/*************************************************************************
	> File Name: D.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int l, x;
double p;
double dp[2010][2010];
int main(){
	cin>>T;
	while(T--){
		cin >> l >> x >> p;
		memset(dp, 0, sizeof(dp));
		dp[0][x] = 1;
		for(int i = 0 ; i <= l ; i++){
			for(int j = x ; j <= l ; j++){
				dp[i + 1][j] += dp[i][j] * p;
				dp[i][j + 1] += dp[i][j] * (1 - p);
			}
		}
		double ans = 0;
		for(int i = x ; i < l ; i++)	ans += dp[i][i];
		cout << fixed << setpresicion(10) << ans << endl;
	}
	return 0;
}
