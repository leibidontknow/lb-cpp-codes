#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int a[220];
void solve(){
	int ans = 0;
	int n;
	cin >> n; 
	for(int i = 1 ; i <= 2 * n ; i++)	cin >> a[i];
	sort(a + 1, a + 1 + 2 * n);
	vector<int>x, y;
	for(int i = 1 ; i <= n ; i++){
		x.push_back(a[i]);
		if(x.size() > 1){
			ans += abs(a[i] - x[x.size() - 2]);
		}
	}
	for(int i = n + 1 ; i <= 2 * n ; i++){
		y.push_back(a[i]);
		if(y.size() > 1){
			ans += abs(a[i] - y[y.size() - 2]);
		}
	}
	cout << ans << endl;
	for(int i = 1 ; i <= n ; i++)	cout << x[i - 1] << ' ' << y[i - 1] << endl;
}
signed main(){
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}