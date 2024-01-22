/*************************************************************************
	> File Name: CF1706E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int a[N], dp[N][25], fa[N], dep[N];
int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
int to[N], nxt[N], head[N];
void add(int u, int v, bool flag = 0){
	static int cnt = 0;
	if(flag == 1){
		cnt = 0;
		memset(head, 0, sizeof(head));
		return;
	}
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	to[++cnt] = u;
	nxt[cnt] = head[v];
	head[v] = cnt;
}
void getdp(int now,int father){
	dp[now][0]=father;
	dep[now]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[now];i++){
		dp[now][i]=dp[dp[now][i-1]][i-1];
	}
	for(int i=head[now];i;i=nxt[i]){
		if(to[i]!=father)	getdp(to[i],now);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b]){
		swap(a,b);
	}
	for(int i=21;i>=0;i--){
		if(dep[a]-(1<<i)>=dep[b])	a=dp[a][i];
	}
	if(a==b){
		return b;
	}
	for(int i=21;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i],b=dp[b][i];
		}
	}
	return dp[b][0];
}
void solve(){
	add(1, 1, 1);
	int id;
	int n, m, q;
	cin >> n >> m >> q;
	id = n + 1;
	int root = 0;
	memset(dp, 0, sizeof(dp));
	for(int i = 1 ; i <= n + m ; i ++)	fa[i] = i, dep[i] = 0;
	for(int i = 1 ; i <= m ; i ++){
		int u, v;
		cin >> u >> v;
		if(Find(u) != Find(v)){

			a[id] = i;
			add(Find(u), id);
			add(Find(v), id);
			fa[Find(u)] = fa[Find(v)] = id;
			root = max(root, id);
		}
		id++;
	}
	getdp(root, root);
	for(int i = 1 ; i <= q ; i ++){
		int l, r;
		cin >> l >> r;
		if(l == r)	cout << 0 << ' ';
		else cout << a[lca(l, r)] << ' ';
	}
	cout << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

