/*************************************************************************
	> File Name: 最大流.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
int n, m, s, t;
int tot;
int to[N], nxt[N], head[N], w[N];
void add(int u, int v, int w){
	static int cnt = 1;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	::w[cnt] = w;
	head[u] = cnt;
}
void addedge(int u, int v, int w){
	add(u, v, w);
	add(v, u, 0);
}
int dep[N], cur[N];
bool bfs(){
	for(int i = 0 ; i <= tot ; i++){
		dep[i] = -1;
		cur[i] = head[i];
	}
	queue<int> q;
	q.push(s);
	dep[s] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dep[v] == -1 && w[i]){
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[t] != -1;
}
int dfs(int u, int flow){
	if(u == t)	return flow;
	int tmp = flow;
	for(int &i = cur[u] ; i && flow ; i = nxt[i]){
		int v = to[i];
		if(dep[v] == dep[u] + 1 && w[i]){
			int x = dfs(v, min(flow, w[i]));
			if(x){
				w[i] -= x;
				w[i ^ 1] += x;
				flow -= x;
			}
		}
	}
	return tmp - flow;
}
int dinic(){
	int ans = 0;
	while(bfs())	ans += dfs(s, INF);
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	tot = n;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	cout << dinic() << endl;
	return 0;
}
