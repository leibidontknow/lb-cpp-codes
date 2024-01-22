#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t;
void solve(){
	int n, maxx = 0, minn = LLONG_MAX;
	vector<int> vec;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x; 
		minn = min(minn, x);
		maxx = max(maxx, x); 
	}
	if(minn == maxx)	return cout << 0 << endl, void();
	while(minn != maxx){
		if(minn > maxx){
			swap(minn, maxx);
		}
		if((maxx & 1) || (maxx % 2 == 0 && minn % 2 == 0)){
			vec.push_back(0);
		}
		else{
			minn++;
			vec.push_back(1);
		}
		minn >>= 1;
		maxx >>= 1;
	}
	cout << vec.size() << endl;
	if(vec.size() <= n){
		for(int v : vec){
			cout << v << ' ';
		}
		cout << endl;
	}

}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}