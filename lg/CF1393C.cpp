#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int t;
int n, a[N];
void solve(){
	unordered_map<int, int>mp;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	int tmp = 0;
	int maxx = 0;
	for(int i = 1 ; i <= n ; i++){
		mp[a[i]]++;
		if(mp[a[i]] > maxx){
			maxx = mp[a[i]];
			tmp = 1;
		}
		else if(mp[a[i]] == maxx){
			tmp++;
		}
	}
	cout << (tmp - 1) + (n - tmp * maxx) / (maxx - 1) << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	solve();
	return 0;
}