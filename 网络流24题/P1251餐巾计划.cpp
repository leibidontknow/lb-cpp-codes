#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int _n, _m, _p, _f, _s, s, t;
int to[N], w[N], c[N], head[N], nxt[N];
int n;
void add(int u, int v, int w, int cst){
	static int cnt = 1;
	to[++cnt] = v;
	::w[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
	c[cnt] = cst;
}
void addedge(int u, int v, int w, int c){
	add(u, v, w, c);
	add(v, u, 0, -c);
}
int dis[N], cur[N], inque[N], cost;
bool spfa(){
	for(int i = 1 ; i <= 2 * n + 2; i++)	dis[i] = inf, cur[i] = head[i], inque[i] = 0;
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
	cin >> n;
	s = 2 * n + 1;
	t = 2 * n + 2;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		addedge(s, i, x, 0);
		addedge(i + n, t, x, 0);
	}
	cin >> _p >> _m >> _f >> _n >> _s;
	for(int i = 1 ; i <= n ; i++){
		addedge(s, i + n, inf, _p);
		if(i + _m <= n)	addedge(i, i + n + _m, inf, _f);
		if(i + _n <= n)	addedge(i, i + n + _n, inf, _s);
		if(i + 1 <= n)	addedge(i, i + 1, inf, 0);
	}
	while(spfa()) dfs(s, inf);
	cout << cost << endl;
	return 0;
}
