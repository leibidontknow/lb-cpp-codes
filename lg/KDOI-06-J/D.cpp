#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, a[2000000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n; 
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		sum ^= a[i];
	}
	cout << sum << ' ' << 0 << endl;
	return 0;
}