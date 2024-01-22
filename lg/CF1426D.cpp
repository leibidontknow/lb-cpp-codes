#include<bits/stdc++.h>
using namespace std;
#define int long long 
int ans = 0;
signed main(){
	unordered_map<int, bool>mp;
	int n, sum, x;
	sum = 0;
	ios::sync_with_stdio(false);
	cin >> n; 
	mp[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		cin >> x;
		sum += x;
		if(mp[sum]){
			mp.clear();
			mp[sum] = 1;
			mp[0] = 1;
			sum = x;
			ans++;
		}
		mp[sum] = 1;
	}
	cout << ans << endl;
	return 0;
}