/*************************************************************************
	> File Name: P2774.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, s, t;
int to[N], w[N], head[N], nxt[N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void add(int u, int v, int w){
	static int cnt = 1;
	to[++cnt] = v;
	::w[cnt] = w;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
void addedge(int u, int v, int w){
	add(u, v, w);
	add(v, u, 0);
}
int dep[N], cur[N];
bool bfs(){
	queue<int>q;
	q.push(s);
	memset(dep, -1, sizeof(dep));
	dep[s]=1;
	for(int i = 0 ; i <= n * m + 10 ; i++)	cur[i] = head[i];
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
int dinic(){
	int ans = 0;
	while(bfs())	ans += dfs(s, inf);
	return ans;
}
int a[200][200];
int P(int x, int y){
	return (x - 1) * m + y;
}
bool check(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int sum = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	s = 0;
	t = n * m + 10;
	//cout << "done\n" ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
			sum += a[i][j];
			if((i + j) & 1){
				addedge(s, P(i, j), a[i][j]);
			}
			else{
				addedge(P(i, j), t, a[i][j]);
			}
		}
		//cout << i << endl;
	}
	//cout << "alive" << endl;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if((i + j) & 1){
				for(int k = 0 ; k < 4 ; k++){
					int xx = i + dx[k];
					int yy = j + dy[k];
					if(check(xx, yy)){
						addedge(P(i, j), P(xx, yy), inf);
					}
				}
			}
		}
	}
	//cout << "alive!" << endl;
	cout << sum - dinic() << endl;
	return 0;
}
