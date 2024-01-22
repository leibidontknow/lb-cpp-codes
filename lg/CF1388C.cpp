#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 3e5 + 10;
int t;
int n, m;
int p[N], h[N], ppl[N];
int to[N], nxt[N], head[N];
void add(int u, int v, bool flag = 0){
	static int cnt = 1;
	if(flag){
		cnt = 1;
		for(int i = 0 ; i <= n ; i++)	head[i] = 0;
			return;
	}
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void addedge(int u, int v){
	add(u, v);
	add(v, u);
}
int pplsum[N];
int good[N];
void dfs1(int u, int fa){
	int sum = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa)	continue;
		dfs1(v, u);
		sum += pplsum[v];
	}
	pplsum[u] = sum + p[u];
}
bool flag = false;
void dfs2(int u, int fa){
	if(flag) return;
	int sum = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(flag) return;
		if(v == fa)	continue;
		dfs2(v, u);
		sum += good[v];
	}
	if((pplsum[u] + h[u]) % 2 == 1){
		flag = true;
		return;
	}
	good[u] = (pplsum[u] + h[u]) / 2;
	if(good[u] < sum){
		flag = true;
		return;
	}
	if(abs(h[u]) > pplsum[u]){
		flag = true;
		return;
	}
}
void solve(){
	flag = false;
	cin >> n >> m;
	add(1, 1, 1);
	for(int i = 1 ; i <= n ; i++)
		cin >> p[i];
	for(int i = 1 ; i <= n ; i++)
		cin >> h[i];
	for(int i = 1 ; i < n ; i++){
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	if(flag)	cout << "NO" << endl;
	else cout << "YES" << endl;
	for(int i = 0 ; i <= n ; i++) {
		pplsum[i] = good[i] = 0;
	}
	// for(int i = 1 ; i <= n ; i++)	cout << good[i] << ':' << pplsum[i] << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	solve();
	return 0;
}