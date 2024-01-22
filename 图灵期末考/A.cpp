/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int p = 1e9 + 7;
const int maxn = 1e7;
int T, n, k;
#define ll long long
ll pow(ll a, ll b, ll m){
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)ans = (ans % m) * (a % m) % m;
        b /= 2;
        a = (a % m) * (a % m) % m;
    }
    ans %= m;
    return ans;}
ll inv(ll x, ll p){
    return pow(x, p - 2, p);
}
ll C(ll n, ll m, ll p){
    if(m > n)return 0;
    ll up = 1, down = 1;
    for(int i = n - m + 1; i <= n; i++) up = up * i % p;
    for(int i = 1; i <= m; i++) down = down * i % p;
    return up * inv(down, p) % p;
}
ll Lucas(ll n, ll m, ll p){
    if(m == 0)return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
signed main(){
	cin >> T >> p;
	//for(int i = 1; i < p; i++)	fac[i] = fac[i-1] * i % p;
	//ext_gcd(fac[p - 1], p,d, x, y);
	//invf[p - 1] = (x + p) % p;
	//for(int i = p - 1 - 1; i >= 0; i--)	invf[i] = invf[i+1] * (i+1) % p;
	while(T--){
		cin >> k >> n;
		int ans=1;
		n = n + k - 1;
		k = k - 1;
		while(n){
			ans *= C(n % p, k % p) % p;
			ans %= p;
			n /= p;
			k /= p;
		}
		cout << ans % p << endl;
	}
	return 0;
}

