#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int to[N], nxt[N], w[N], head[N];
int dis[N], vis[N];
void add(int u, int v, int w){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	::w[cnt] = w;
} 
int n, m, s;
struct node{
	int u, dis;
	node(int a, int b):u(a), dis(b){}
	bool operator<(const node &b)const{
		return dis > b.dis;
	}
};
priority_queue<node> pq;
int k, d;
int ans = 0;
int p[2000000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> d;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w;
		u++, v++;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> p[i];
		p[i]++;
	}
	s = 1;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	pq.push(node(s, 0));
	while(!pq.empty()){
		int u = pq.top().u;
		pq.pop();
		if(vis[u])	continue;
		vis[u] = 1;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] > dis[u] + w[i]){
				dis[v] = dis[u] + w[i];
				pq.push(node(v, dis[v]));
			}
		}
	}
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1 ; i <= k ; i++){
		ans = min(ans, dis[p[i]]);
	}
	if(ans == 0x3f3f3f3f3f3f3f3f){
		cout << -1 << endl;
	}
	else{
		cout << ans * d << endl;
	}
	return 0;
}