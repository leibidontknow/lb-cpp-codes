#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int mod = 998244353;
int n, m;
const int N = 2e6 + 10;
int a[N], b[N];
int ans = 1;
int s[N];
unordered_map<int, int>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i <= m ; i++)
		cin >> b[i];
	s[n + 1] = 0x3f3f3f3f3f3f3f3f;
	for(int i = n ; i >= 1 ; i--){
		s[i] = min(s[i + 1], a[i]);
		mp[s[i]]++;
	}
	for(int i = 2 ; i <= m ; i++){
		ans = (ans * mp[b[i]]) % mod;
	}	
	if(s[1] != b[1])
		ans = 0;
	cout << ans << endl;
	return 0;
}