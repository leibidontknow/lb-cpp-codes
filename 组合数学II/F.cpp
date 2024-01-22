/*************************************************************************
	> File Name: F.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T, n, m, k;
int fastpow(int n,int k){	
	if(k==0)	return 1;
	int tmp=fastpow(n,k/2);
	tmp=tmp*tmp%p;
	if(k&1)	tmp = (tmp * n) % p;
	return tmp;
}
int dp[1919810];
signed main(){
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		m /= k;
		ans = 0;
		for(int i = m ; i >= 1 ; i--){
			dp[i] = fastpow(m / i, n);
			for(int j = i + i ; j <= m ; j += i)	dp[i] = (dp[i] - dp[j]) % p;
			
		}
		cout << (f[1] + p) % p << endl;
	}
	return 0;
}
