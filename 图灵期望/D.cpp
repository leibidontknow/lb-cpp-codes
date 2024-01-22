/*************************************************************************
	> File Name: D.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n, k;
double p[1919810], dp[1919810];
int main(){
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> p[i];
		dp[i] = 1e50;
	}
	for(int i = 0 ; i < n ; i++){
		double sum = 0;
		for(int j = i + 1 ; j <= n && j <= i + 8 ; j++){
			int tmp = (1 - p[j]) / p[j] * sum + 1 / p[j];
			sum += tmp;
			dp[j] = min(dp[j], dp[i] + sum + k);
		}
	}
	cout << fixed << setprecision(10) << dp[n];
	return 0;
}
