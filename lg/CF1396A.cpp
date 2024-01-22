#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, a[1919810];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << "1 1\n" << -a[1] << "\n1 1\n0\n1 1\n0" << endl;
		return 0;
	}
	cout << 1 << ' ' << n - 1 << endl;
	for(int i = 1 ; i < n ; i++){
		cout << a[i] * (n - 1) << ' ';
	}
	cout << endl;
	cout << n << ' ' << n << endl;
	cout << a[n] * (n - 1) << endl;
	cout << 1 << ' ' << n << endl;
	for(int i = 1 ; i <= n ; i++){
		cout << -a[i] * n << ' ';
	}
	cout << endl;
	return 0;
}