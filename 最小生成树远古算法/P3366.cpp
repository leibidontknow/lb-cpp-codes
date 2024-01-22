/*************************************************************************
	> File Name: P3366.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5919810;
int fa[N], siz[N];
int to[N], head[N], nxt[N], w[N];
void add(int u, int v, int w){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	::w[cnt] = w;
}
void addedge(int u, int v, int w){
	add(u, v, w);
	add(v, u, w);
}
int n, m;
int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y){
	int gx = Find(x), gy = Find(y);
	if(gx == gy) return;
	if(siz[gx] > siz[gy]){
		fa[gy] = gx;
		siz[gx] += siz[gy];
	}
	else{
		fa[gx] = gy;
		siz[gy] += siz[gx];
	}
}
int boruvka(){
	int sum = 1, ans = 0;
	int link[N];
	int val[N];
	for(int i = 1 ; i <= n ; i++){
		fa[i] = i;
		siz[i] = i;
	}
	while(sum++){
		memset(link, 0x3f, sizeof(link));
		memset(val, 0x3f, sizeof(val));
		for(int i = 1 ; i <= n ;i++){
			int gu = Find(i);
			for(int j = head[i] ; j ; j = nxt[j]){
				int v = to[j];
				int gv = Find(v);
				if(w[j] >= val[gu] || gu == gv)	continue;
				link[gu] = gv;
				val[gu] = w[j];
			}
		}
		for(int i = 1 ; i <= n ; i++){
			if(i != fa[i])	continue;
			int gi = Find(i);
			int v = link[gi];
			int gv = Find(v);
			if(!v || gi == gv)	continue;
			ans += val[gi];
			Union(gi, gv);
		}
		int rot = 0;
		for(int i = 1 ; i <= n ; i++){
			if(Find(i) == i)	rot++;
		}
		if(rot == 1){
			sum = 0;
		}
		if(sum > sqrt(n + 1)){
			cout << "orz" << endl;
			return 0;
		}
	}
	return ans;
}
signed main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	int ans = boruvka();
	if(!ans) cout<<"orz\n"; 
	else cout << ans << endl;
	return 0;
}
