#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
const int N = 5e6 + 10;
int a[N];
int b[N];
int s[N];
int n;
int C(int n, int k){
	int res = 1;
	for(int i = 1 ; i <= k ; i++){
		res *= (n - i + 1);
	}
	for(int i = 1 ; i <= k ; i++)
		res /= i;
	return res; 
}
void solve(){
	int ans = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i], b[a[i]]++;
	s[0] = b[0];
	for(int i = 1 ; i <= n ; i++)
		s[i] = s[i - 1] + b[i];
	for(int i = 0 ; i <= n ; i++){
		if(b[i] < 2)
			continue;
		if(i > 0) ans += C(b[i], 2) * s[i - 1];
		if(b[i] > 2)
			ans += C(b[i], 3);
	}
	for(int i = 0 ; i <= n ; i++)
		b[i] = 0;
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}