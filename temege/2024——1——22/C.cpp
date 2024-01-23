#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
const int N = 2e6 + 10;
int n, m;
int fa[N];
int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y){
	int fx = Find(x), fy = Find(y);
	if(fx != fy)
		fa[fx] = fy;
}
void solve(){
	cin >> n >> m; 
	for(int i = 0 ; i <= 2 * n ; i++){
		fa[i] = i;
	}
	for(int i = 1 ; i <= m ; i++){
		int x, y; 
		string s;
		cin >> x >> y >> s;
		if(s[0] == 'i'){
			Union(x + n, y);
			Union(x, y + n);
		}
		else{
			Union(x, y);
			Union(x + n, y + n);
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(Find(i) == Find(i + n)){
			cout << "-1" << endl;
			return;
		}
	}
	int ans1 = 0, ans2 = 0;
	int tmp = Find(1);
	for(int i = 1 ; i <= n ; i++){
		if(Find(i) == tmp)
			ans1++;
		else
			ans2++;
	}
	cout << max(ans1, ans2) << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}