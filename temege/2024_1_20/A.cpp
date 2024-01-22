#include<bits/stdc++.h> 
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

using namespace std;
#define int long long 
const int mod = 998244353;
const int N = 5010;
int ans[N][N];
int p, t;
void print(){
	int res = 0;
	int tmp = 1;
	for(int i = 1 ; i < p ; i++){
		for(int j = 1 ; j < p ; j++){
			res = (res + (ans[i][j] * tmp) % mod) % mod;
			tmp = (tmp * t) % mod;
		}
	}
	// for(int i = 1 ; i < p ; i++){
	// 	for(int j = 1 ; j < p ; j++){
	// 		cout << ans[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	cout << res << endl;
}
const int M = N;
int to[M], nxt[M], w[M], head[M];
int dis[M], vis[M];
void add(int u, int v, int w){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u]; 
	head[u] = cnt;
	::w[cnt] = w;
}
struct node{
	int u, dis;
	node(int a, int b):u(a), dis(b){}
	bool operator<(const node &b)const{
		return dis > b.dis;
	}
};
priority_queue<node>pq;
void dijkstra(int s){
	for(int i = 0 ; i <= p ; i++)
		dis[i] = 0x3f3f3f3f3f3f3f3f, vis[i] = 0;
	dis[s] = 0;
	pq.push(node(s, 0));
	while(!pq.empty()){
		int u = pq.top().u;
		pq.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(dis[v] > dis[u] + w[i]){
				dis[v] = dis[u] + w[i];
				pq.push(node(v, dis[v]));
			}
		}
	}
	// cout << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> p >> t;
	for(int i = 1 ; i < p ; i++){
		for(int z = 1 ; z < p ; z++){
			if(abs(i - z) > 17)
				continue;
			int v = i * z % p;
			add(i, v, abs(i - z));
		}
	}
	for(int i = 1 ; i < p ; i++){
		dijkstra(i);
		for(int j = 1 ; j < p ; j++){
			ans[i][j] = dis[j];
		}
	}
	print();
	return 0;
}