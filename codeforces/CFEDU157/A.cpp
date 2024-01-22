#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T;
int f(int x){
	if(x > 0)	return x;
	return 0;
}
void solve(){
	int x, y, k;
	cin >> x >> y >> k;
	if(y <= x)	cout << x << endl;
	else{
		int tmp = min(y - x, k);
		cout << x + tmp + f(y - x - tmp) + f(y - (x + tmp)) << endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)	solve();
	return 0;
}