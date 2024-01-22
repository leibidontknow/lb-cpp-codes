#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
int n;
int a[20];
void solve(){
	cin >> n; 
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	if(a[1] == 1)	cout << "YES" << endl;
	else cout << "NO" << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}