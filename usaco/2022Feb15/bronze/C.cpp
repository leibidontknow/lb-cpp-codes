#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int T, n;
const int N = 2e6 + 10;
struct node{
	int h, a, t;
	bool operator<(const node &b)const{
		return h > b.h;
	}
}a[N];
void solve(){
	cin >> n; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].h; 
	}
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i].a; 
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i].t; 
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
		solve();
	return 0;
}