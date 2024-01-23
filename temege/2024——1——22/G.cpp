#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int mod = 1e9 + 7; 
int t;
int n, k;
int C[2010][2010];
int a[2010];
void init(){
	for(int i = 1 ; i <= 1010 ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(i == j || j == 0)
				C[i][j] = 1;
			else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j] )% mod;
		}
	}
}
void solve(){
	unordered_map<int, int> mp;
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	int ans = 0;
	int sum = 0;
	for(int i = n ; i >= 1 ; i--){
		if(sum + mp[i] < k)
			sum += mp[i];
		else{
			ans = C[mp[i]][min(k - sum, mp[i] - k + sum)];
			break;
		}
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	init();
	while(t--)
		solve();
	return 0;
}