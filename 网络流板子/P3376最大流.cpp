/*************************************************************************
	> File Name: P3376最大流.cpp
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
int to[N], w[N], head[N], nxt[N];
void add(int u, int v, int w){
	static int cnt = 1;
	to[++cnt] = v;
	::w[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int dep[N], cur[N];
bool bfs(){
	queue<int>q;
	q.push(s);
	memset(dep, -1, sizeof(dep));
	dep[s]=1;
	for(int i = 1 ; i <= n ; i++)	cur[i] = head[i];
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v=to[i];
			if(dep[v]!=-1 || !w[i])	continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	return dep[t]!=-1;
}
int dfs(int s, int flow){
	if(s == t)	return flow;
	int tmp = flow;
	for(int &i = cur[s]; i && flow ; i = nxt[i]){
		int v = to[i];
		if(!w[i] || dep[v] != dep[s] + 1)	continue;
		int x = dfs(v, min(flow, w[i]));
		if(x){
			flow -= x;
			w[i] -= x;
			w[i ^ 1] += x;
		}
	}
	return tmp - flow;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	for(int i = 1 ; i <= m ; i++){
		int u, v, flw;
		cin >> u >> v >> flw;
		add(u, v, flw);
		add(v, u, 0);
	}
	int ans = 0;
	while(bfs()) ans += dfs(s, inf);
	cout << ans << endl;
	return 0;
}
