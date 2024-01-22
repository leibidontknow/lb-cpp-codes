#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
int c[200000 + 10];
int d[200000 + 10];
void solve(){
	int n;
	cin >> n; 
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> c[i];
		if(c[i] - c[i - 1] > 0)	ans += c[i] - c[i - 1];
	}
	cout << ans - 1 << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	
		solve();
	return 0;
}