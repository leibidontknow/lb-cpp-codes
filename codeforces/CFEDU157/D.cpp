#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, a[300010], b[300010];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n; 
	for(int i = 1 ; i < n ; i++){
		cin >> a[i];
	}
	b[1] = 0;
	for(int i = 2 ; i <= n ; i++){
		b[i] = a[i - 1] ^ b[i - 1];
	}
	for(int i = 1 ; i <= n ; i++)	cout << b[i] << ' ';
		cout << endl;
	return 0;
}