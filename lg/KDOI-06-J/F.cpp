#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, a[2000000 + 10], ans = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0 ; i <= n ; i++){
		cin >> a[i];
		if(a[i - 1] > 0 && a[i] < 0 || a[i - 1] < 0 && a[i] > 0)
			ans++;
	}
	cout << ans<< endl;
	return 0;
}