#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
const int N = 5e6 + 10;
int a[N];
int col[N], dis[N];
int col_sum[N];
int num;
int to[N], nxt[N], head[N];
int top = 0;
int stk[N]; 
int dfn[N], low[N];
bool instk[N];
int cnt = 0;
int in[N];
int b[N];
void add(int u, int v){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
} 
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	stk[++top] = u;
	instk[u] = 1;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(instk[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		col[u] = ++num;
		col_sum[u] = 1;
		while(true){
			int x = stk[top--];
			col[x] = num;
			instk[x] = 0;
			b[col[u]] += a[x];
			if(x == u)	break;
			col_sum[num]++;
		}
	}
}
int hed[N], too[N], nex[N];
#define head hed
#define to too
#define a b
#define nxt nex
#define n num
void add2(int u, int v){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
} 
void topo(){
	int ans;
	queue<int>q;
	for(int i = 1 ; i <= n ; i++){
		if(!in[i])	q.push(i);
		dis[i] = a[i];
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			dis[v] = max(dis[v], dis[u] + a[v]);
			in[v]--;
			if(in[v] < 1)	q.push(v);
		}
	}
	ans = 0;
	for(int i = 1 ; i <= n ; i++)	ans = max(ans, dis[i]);
	cout << ans << endl;
	return;
}
#undef n
#undef head
#undef to
#undef nxt
#undef a
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i];
	for(int i = 1 ; i <= m ; i++){
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	for(int i = 1 ; i <= n ; i++)	if(!dfn[i])	tarjan(i);
	for(int i = 1 ; i <= n ; i++){
		for(int j = head[i] ; j ; j = nxt[j]){
			int v = to[j];
			if(col[i] != col[v])	add2(col[i], col[v]), in[col[v]]++;
		}
	} 
	topo();
	return 0; 
}