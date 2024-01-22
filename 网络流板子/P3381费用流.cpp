/*************************************************************************
	> File Name: P3381费用流.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月08日 星期二 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, s, t;
int to[N], w[N], c[N], head[N], nxt[N];
void add(int u, int v, int w, int cst){
	static int cnt = 1;
	to[++cnt] = v;
	::w[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
	c[cnt] = cst;
}
int dis[N], cur[N], inque[N], cost;
bool spfa(){
	for(int i = 1 ; i <= n ; i++)	dis[i] = inf, cur[i] = head[i], inque[i] = 0;
	queue<int>q;
	q.push(s);
	inque[s] = 1;
	dis[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inque[u] = 0;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] > dis[u] + c[i] && w[i]){
				dis[v] = dis[u] + c[i];
				if(!inque[v])	q.push(v), inque[v] = 1;
			}
		}
	}
	return dis[t]!=inf;
}
int vis[N];
int dfs(int s, int flow){
	if(s == t)	return flow;
	int tmp = flow;
	vis[s] = 1;
	for(int &i = cur[s]; i && flow ; i = nxt[i]){
		int v = to[i];
		if(dis[v] != dis[s] + c[i] || vis[v])	continue;
		int x = dfs(v, min(flow, w[i]));
		if(x){
			flow -= x;
			w[i] -= x;
			w[i ^ 1] += x;
			cost += x * c[i];
		}
	}
	vis[s] = 0;
	return tmp - flow;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	for(int i = 1 ; i <= m ; i++){
		int u, v, flw, cst;
		cin >> u >> v >> flw >> cst;
		add(u, v, flw, cst);
		add(v, u, 0, -cst);
	}
	int ans = 0;
	while(spfa()) ans += dfs(s, inf);
	cout << ans << ' ' << cost << endl;
	return 0;
}
