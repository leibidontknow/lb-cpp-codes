/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 998244353;
int fastpow(int n, int k){
	int ans = 1;
	while(k){
		if(k & 1)	ans = (ans * n) % mod;
		k >>= 1;
		n = (n * n) % mod;
	}
	return ans;
}
int Ln, Gn, LP[1919810], GP[1919810];
unordered_map<int, int>L, G;
int ans = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin >> Ln;
	for(int i = 1 ; i <= Ln ; i++){
		cin >> LP[i];
	}
	for(int i = 1 ; i <= Ln ; i++){
		cin >> L[LP[i]];
	}
	cin >> Gn;
	for(int i = 1 ; i <= Gn ; i++){
		cin >> GP[i];
	}
	for(int i = 1 ; i <= Gn ; i++){
		cin >> G[GP[i]];
		if(G[GP[i]] > L[GP[i]]){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 1 ; i <= Ln ; i++){
		//int tmp = (L[LP[i]] - G[LP[i]]) / 2 + 1;
		ans += bool(L[LP[i]] - G[LP[i]]);
		//cout << LP[i] << ':' << ' ' << L[LP[i]] << ',' << G[LP[i]] << endl;
	}
	cout << fastpow(2, ans) << endl;
	return 0;
}
