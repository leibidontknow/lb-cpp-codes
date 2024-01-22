/*************************************************************************
	> File Name: P4016.cpp
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
int tot, cost = 0;
int to[N], nxt[N], head[N], w[N], c[N];
void add(int u, int v, int w, int c){
	static int cnt = 1;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	::w[cnt] = w;
	::c[cnt] = c;
	head[u] = cnt;
}
void addedge(int u, int v, int w, int c){
	add(u, v, w, c);
	add(v, u, 0, -c);
}
int dis[N], cur[N], inque[N];
bool spfa(){
	for(int i = 0 ; i <= tot ; i++){
		dis[i] = INF;
		cur[i] = head[i];
		inque[i] = 0;
	}
	queue<int> q;
	inque[s] = 1;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inque[u] = 0;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(w[i] && dis[v] > dis[u] + c[i]){
				dis[v] = dis[u] + c[i];
				if(!inque[v]){
					inque[v] = 1;
					q.push(v);
				} 
			}
		}
	}
	return dis[t] != INF;
}
int vis[N];
int dfs(int u, int flow){
	if(u == t)	return flow;
	int tmp = flow;
	vis[u] = 1;
	for(int &i = cur[u] ; i && flow ; i = nxt[i]){
		int v = to[i];
		if(dis[v] == dis[u] + c[i] && w[i] && !vis[v]){
			int x = dfs(v, min(flow, w[i]));
			if(x){
				w[i] -= x; 
				w[i ^ 1] += x;
				flow -= x;
				cost += x * c[i];
			}
		}
	}
	vis[u] = 0;
	return tmp - flow;
}
int dinic(){
	int ans = 0;
	while(spfa())	ans += dfs(s, INF);
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	tot = n + 2;
	s = n + 1;
	t = n + 2;
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		sum += x;
		addedge(s, i, x, 0);
	}
	sum /= n;
	for(int i = 1 ; i < n ; i++){
		addedge(i, t, sum, 0);
		addedge(i, i + 1, INF, 1);
		addedge(i + 1, i, INF, 1);
	}
	addedge(n, t, sum, 0);
	addedge(n, 1, INF, 1);
	addedge(1, n, INF, 1);
	dinic();
	cout << cost << endl;
	return 0;
}


