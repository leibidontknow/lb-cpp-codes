#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
void solve(){
	int n, x;
	int a[200];
	cin >> n >> x;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i];
	int maxx = 0;
	int tmp = 0;
	int id = 1;
	for(int i = 1 ; i <= x ; i++){
		tmp++;
		maxx = max(maxx, tmp);
		if(a[id] == i && id <= n){
			tmp = 0;
			id++;
		}
	}
	id = n;
	for(int i = x - 1 ; i >= 0 ; i--){
		tmp++;
		maxx = max(maxx, tmp);
		if(a[id] == i && id >= 1){
			tmp = 0;
			id--;
		}
	}
	cout << maxx << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t; 
	while(t--)	solve();
}