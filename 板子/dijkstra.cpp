#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int to[N], nxt[N], head[N], w[N];
void add(int u, int v, int w){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
	::w[cnt] = w;
}
int dis[N], 