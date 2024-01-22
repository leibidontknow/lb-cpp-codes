#include<bits/stdc++.h> 
using namespace std;
int t;
int n;
const int N = 2e5 + 10;
int a[N];
int dp[N];
int b[N];
int ans = 0;
void solve(){
	int ans = 0;
	cin >> n; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		dp[i] = 1;
	}
	memset(b, 0, sizeof(b));
	sort(a + 1, a + 1 + n);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j * j <= a[i] ; j++){
			if(a[i] % j == 0){
				if(b[j])
					dp[i] = max(dp[i], dp[b[j]] + 1);
				if(b[a[i] / j])
					dp[i] = max(dp[i], dp[b[a[i] / j]] + 1);
			}
		}
		b[a[i]] = i;
		ans = max(ans, dp[i]);
	}
	cout << n - ans << endl;
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}