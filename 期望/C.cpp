/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
double dp[2010][2010];
double p[2010];
double ans;
int main(){
	cin >> T;
	for(int i = 1 ; i <= T ; i++)	cin >> p[i];
	dp[0][0] = 1;
	for(int i = 0 ; i < T ; i++){
		for(int j = 0 ; j < T ; j++){
			dp[i + 1][j + 1] += dp[i][j] * p[i+1];
			dp[i + 1][j] += dp[i][j] * (1 - p[i+1]);
		}
	}
	for(int i = 0 ; i <= T ; i++){
		if (i > T - i) ans += dp[T][i];
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
