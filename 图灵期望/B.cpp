/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
double dp[210][210][210];
int n, cnt[4];
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 0 ; i <= c[3] ; i++){
		for(int j = 0 ; j <= c[2] + c[3] ; j++){
			for(int k = 0 ; k <= c[1] + c[2] + c[3] ; k++){
				if(!i && !j && !k){
					dp[i][j][k] = 0; 
					continue;
				}
				if(i > 0)	dp[i][j][k] += dp[i - 1][j + 1][k] * i / (i + j + k);
				if(j > 0)	dp[i][j][k] += dp[i][j - 1][k + 2] * j / (i + j + k);
				if(k > 0)	dp[i][j][k] += dp[i][j][k - 1] * k / (i + j + k);
				dp[i][j][k] += 1.0 * n / (i + j + k);
			}
		}
	}
	cout << fixed << setprecision(20) << dp[c[3][c[2]][c[1]]] << endl;
}
