/*************************************************************************
	> File Name: P5431.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, a[5919810], p, k;
int s[5919810], sv[5919810];
inline int fastpow(int n, int k){
	int res = 1;
	while(k){
		if(k & 1) res = (res * n) % p;
		n = n * n % p;
		k >>= 1;
	}
	return res % p;
}
inline void read(int &tar){
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	tar = x * f;
}
int ans = 0;
signed main(){
	//ios::sync_with_stdio(false);
	read(n);
	read(p);
	read(k);
	s[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		read(a[i]);
		s[i] = s[i-1] * a[i] % p;
	}
	sv[n] = fastpow(s[n], p - 2);
	for(int  i = n - 1 ; i >= 1 ; i --){
		sv[i] = sv[i + 1] * a[i + 1] % p;
	}
	int tmp = k;
	for(int i = 1 ; i <= n ; i++){
		ans = (ans + tmp * sv[i] % p * s[i - 1] % p) % p;
		tmp = (tmp * k) % p;
	}
	cout << ans << endl;
	return 0;
}
