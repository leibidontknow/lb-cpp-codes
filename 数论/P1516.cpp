/*************************************************************************
	> File Name: P1516.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 10;
int exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int ans = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return ans;
}
signed main(){
	int n, A, B, m, a, x, y, b, l;
	cin >> a >> b >> m >> n >> l;
	A = a - b;
	B = n - m;
	if(B < 0){
		A = -A, B = -B;
	}
	int p = exgcd(B, l, x, y);
	if(A % p != 0){
		puts("Impossible");
	}
	else{
		cout << ((x * (A / p)) % (l / p) + (l / p)) % (l / p) << endl;
	}
	return 0;
}
