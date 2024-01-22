#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
const int N = 2e6 + 10;
int a[N];
int dis1[N], dis2[N];
int n, m;
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i], dis1[i] = dis2[i] = 0;
	a[0] = a[n + 1] = -0x3f3f3f3f3f3f3f3f;
	a[n + 1] = -a[n + 1];
	for(int i = 2 ; i <= n ; i++){
		if(a[i] - a[i - 1] < a[i - 1] - a[i - 2]){
			dis1[i] = dis1[i - 1] + 1;
		}
		else{
			dis1[i] = a[i] - a[i - 1] + dis1[i - 1];
		}
	}
	for(int i = n - 1 ; i >= 1 ; i--){
		if(a[i + 1] - a[i] < a[i + 2] - a[i + 1]){
			dis2[i] = dis2[i + 1] + 1;
		}
		else{
			dis2[i] = dis2[i + 1] + a[i + 1] - a[i];
		}
	}
	cin >> m;
	for(int i = 1 ; i <= m ; i++){
		int x, y;
		cin >> x >> y;
		if(y > x){
			cout << dis1[y] - dis1[x] << endl;
		}
		else{
			cout << dis2[y] - dis2[x] << endl;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}