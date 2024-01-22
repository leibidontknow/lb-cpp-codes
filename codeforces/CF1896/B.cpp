#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
bool vis[200000 + 10];
void solve(){
	int n; 
	string s; 
	cin >> n >> s;
	int ans = 0;
	for(int i = 0 ; i <= n ; i++)	vis[i] = 0;
	for(int i = n - 1 ; i > 0 ; i--){
		if(s[i] == 'B' && s[i - 1] == 'A'){
			int idx = i - 1;
			while(!vis[idx] && s[idx + 1] == 'B'){
				swap(s[idx + 1], s[idx]);
				ans++;
				vis[idx] = 1;
				idx++;
			}
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