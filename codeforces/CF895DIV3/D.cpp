/*************************************************************************
	> File Name: D.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T;
int n, x, y;
int add(int l, int r){
	return (l + r) * (r - l + 1) / 2;
}
int gcd(int a, int b){
	if(b == 0)	return a;
	return gcd(b, a % b);
}
signed main(){
	cin >> T;
	while(T--){
		cin >> n >> x >> y;
		int tmp1 = n / x;
		int tmp2 = n / y;
		int tmp3 = n / (x * y / gcd(x, y));
		tmp1 -= tmp3;
		tmp2 -= tmp3;
		int ans = add(n - tmp1 + 1, n);
		ans -= add(1, tmp2);
		cout << ans << endl;
	}
	return 0;
}
