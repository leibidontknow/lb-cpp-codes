/*************************************************************************
	> File Name: D.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, m;
int dp[1919810],ans;
signed main(){
	cin >> T;
	while(T--){
		cin >> n >> m;
		ans = 0;
		for(int i = min(n, m) ; i >= 1 ; i--){
			dp[i] = (n / i) * (m / i);
			for(int j = j = i ; j <= n && j <= m ; j += i){
				dp[i] -= dp[j];
			}
			ans += i * dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}
