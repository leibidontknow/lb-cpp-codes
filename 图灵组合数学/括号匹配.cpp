/*************************************************************************
	> File Name: 组合数计算.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月07日 星期一 09时28分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 7;
const int maxn = 2e7;
int T, n, k;
int fac[maxn + 10], invf[maxn + 10];
void ext_gcd(long long a,long long b,long long &d,long long &x,long long &y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        ext_gcd(b,a%b,d,y,x);
        y -= a / b * x;
    }
}
int C(int n, int m){
	if(n < 0 || m < 0 || m > n)	return 0;
	return fac[n] * invf[m] % p * invf[n - m] % p;
}
signed main(){
	fac[0] = 1;
	for(int i = 1; i <= maxn; i++)	fac[i] = fac[i-1] * i % p;
	int d, x, y;
	ext_gcd(fac[maxn], p, d, x, y);
	invf[maxn] = (x + p) % p;
	for(int i = maxn - 1; i >= 0; i--)	invf[i]= invf[i+1] * (i+1) % p;
	cin >> T;
	while(T--){
		cin >> n;
		cout << fac[n * 2] * invf[n] % p * invf[n + 1] % p << endl;
	}
	return 0;
}
