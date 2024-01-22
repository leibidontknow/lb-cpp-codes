#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod1 = 1e9 + 7;
const int mod2 = 133333331;
const int N = 1e6 + 10;
int t, n, a[N], p;
int fastpow(int n, int k, int mod){
	int ans = 1;
	while(k){
		if(k & 1)	ans = (ans * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}
	return ans;
}
bool cmp(int a, int b){return a > b;}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		int t1 = 0, t2 = 0;
		cin >> n >> p;
		for(int i = 1 ; i <= n ; i++)	cin >> a[i];
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1 ; i <= n ; i++){
			if(!t1 && !t2){
				t1 = fastpow(p, a[i], mod1);
				t2 = fastpow(p, a[i], mod2);
			}
			else{
				t1 = ((t1 - fastpow(p, a[i], mod1)) % mod1 + mod1) % mod1; 
				t2 = ((t2 - fastpow(p, a[i], mod2)) % mod2 + mod2) % mod2; 
			}
		}
		cout << t1 << endl;
	}
	return 0;
}