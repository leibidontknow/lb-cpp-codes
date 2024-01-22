#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
const int N = 3e3 + 10;
int n, a[N];
int sum[N][N];
int ans = 0;
void solve(){
	ans = 0;
	cin >> n;
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= n ; j++)
			sum[i][j] = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		for(int j = 1 ; j <= n ; j++){
			sum[i][j] = sum[i - 1][j];
		}
		sum[i][a[i]]++;
	}
	for(int j = 2 ; j < n - 1 ; j++){
		for(int k = j + 1 ; k < n ; k++){
			// cout << j << ' ' << k << ' ' << ans << endl;
			ans += (sum[j - 1][a[k]]) * (sum[n][a[j]] - sum[k][a[j]]);
			
		}
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}