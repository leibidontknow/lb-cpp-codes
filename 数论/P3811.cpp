/*************************************************************************
	> File Name: P3811.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int inv[1919810];
int n, p;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> p;
	inv[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		inv[i] = (p - p / i) * inv[p % i] % p;
		cout << inv[i] << endl;
	}
	return 0;
}
