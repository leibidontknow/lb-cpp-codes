#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t;
string s;
int gcd(int a, int b){
	if(b > a)	swap(a, b);
	if(b == 0)	return a;
	return gcd(b, a % b);
}
void solve(){
	int n, k;
	cin >> n >> k;
	cin >> s;
	int a[1000];
	memset(a, 0, sizeof(a));
	for(char ch : s)	a[ch]++;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		int l = gcd(i, k);
		int tmp = 0;
		for(int j = 'a' ; j <= 'z' ; j++)
			tmp += a[j] / (i / l);
		if(tmp >= l){
			ans = max(ans, i);
		}
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	solve();
	return 0;
}