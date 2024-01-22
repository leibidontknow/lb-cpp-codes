/*************************************************************************
	> File Name: P4013.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5+10;
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
void addedge(int u, int v, int w, int cst){
	add(u, v, w, cst);
	add(v, u, 0, -cst);
}
int dis[N], cur[N], inque[N], cost;
bool spfa(){
	for(int i = 0 ; i <= 1919810 ; i++)	dis[i] = -inf, cur[i] = head[i], inque[i] = 0;
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
			if(dis[v] < dis[u] + c[i] && w[i]){
				dis[v] = dis[u] + c[i];
				if(!inque[v])	q.push(v), inque[v] = 1;
			}
		}
	}
	return dis[t] > 0;
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
int m[100][100];
int P(int x, int y){
	return m[x][y];
}
int dinic(){
	int ans = 0;
	while(spfa())	ans += dfs(s, inf);
	return ans;
}
int ti[100][100];
int tu;
int tot = 3;
signed main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m + i - 1 ; j++){
			cin >> ti[i][j];
			m[i][j] = ++tot;
		}
	}
	s = 1;
	t = 2;
	tu = tot;
	for(int i = 1 ; i <= m ; i++)	addedge(s, P(1, i), 1, 0);
	for(int i = 1 ; i <= i + m - 1 ; i++)	addedge(P(n, i) + tu, t, 1, ti[n][i]);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m + i - 1 ; j++){
			addedge(P(i, j), P(i, j) + tu, 1, 0);
			if(i < n){
				addedge(P(i, j) + tu, P(i + 1, j), 1, ti[i][j]);
				if(j < m + i - 1){
					addedge(P(i, j) + tu, P(i + 1, j + 1), 1, ti[i][j]);
				}
			}
		}
	}
	cout << "alive" << endl;
	dinic();
	cout << cost << endl;
	return 0;
}
