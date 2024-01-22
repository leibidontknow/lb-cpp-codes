/*************************************************************************
	> File Name: 第二类斯特林数.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月07日 星期一 11时02分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e3;
#define int long long 
int T,n,k;
int s2[maxn+10][maxn+10];
signed main(){
	s2[0][0] = 1;
	for(int i = 1; i <= maxn; i++){
		s2[i][0] = 0;
		for(int j = 1; j <= i; j++){
			s2[i][j] = (s2[i - 1][j - 1]+s2[i - 1][j] * j) % mod;
		}
	}
	cin >> T;
	while(T--){
		cin >> n >> k;
		cout<< s2[n][k] << endl;
	}
	return 0;
}
