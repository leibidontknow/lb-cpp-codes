#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
const int N = 1e6 + 10;
int a[N];
int n;
void solve(){
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1 ; i <= n ; i++){
		a[i] = s[i - 1] - '0' - 1;
	}
	int ans = 0;
	unordered_map<int, int>mp;
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum += a[i];
		if(sum == 0) ans++;
		ans += mp[sum];	
		mp[sum]++;
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	solve();
	return 0;
}