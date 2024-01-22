#include<bits/stdc++.h> 
using namespace std;
int T, n, q;
const int N= 2e5 + 10;
int to[N], head[N], w[N], nxt[N];
int dis[200000 + 10];
int ans = 0;
void add(int u, int v, int w){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	::w[cnt] = w; 
	head[u] = cnt;
}
int f(char ch){
	if(ch >= '0' && ch <= '9')	return ch - '0';
	if(ch >= 'a' && ch <= 'z')	return ch - 'a' + 10;
	return ch - 'A' + 37;
}
struct Tree{
	int son[2];
	int &operator[](int idx){
		return son[idx];
	}
	const int &operator[](int idx)const{
		return son[idx];
	}
	int cnt;
}t[3000000 + 10];
int idx = 0;
void insert(int x){
	int now = 0;
	for(int i = 30 ; i >= 0 ; i--){
		int k = bool(x & (1 << i));
		if(!t[now].son[k])	t[now].son[k] = ++idx;
		now = t[now].son[k];
	}
	t[now].cnt++;
}
void query(int x){
	int sum = 0;
	int now = 0;
	for(int i = 30 ; i >= 0 ; i--){
		int k = (int(bool(x & (1 << i)))) ^ 1;
		if(t[now].son[k]){
			now = t[now].son[k];
			sum |= (1 << i);
		}
		else{
			now = t[now].son[k ^ 1];
		}
	}
	ans = max(sum, ans);
}
char str[3000000 + 10];
void clear(int now){
	t[now].cnt = 0;
	for(int i = 0 ; i < 65 ; i++){
		if(t[now][i])	clear(t[now][i]), t[now][i] = 0;
	}
}
void dfs(int u, int fa){
	insert(dis[u]);
	query(dis[u]);
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa)	continue;
		dis[v] = dis[u] ^ w[i];
		dfs(v, u); 
	}
}
void solve(){
	idx = 0;
	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, 1);
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}