/*************************************************************************
	> File Name: P2765魔术球.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e4;
const int NN = 3e4;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, s = 0, t;
int sqr[N];
int to[N], w[N], head[N], nxt[N], pd[N], e[N];
int sum;
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
bool ispf(int s){
	for(int i = 1 ; i * i <= s ; i++){
		if(i * i == s) return true;
	}
	return false;
}
bool bfs(){
	queue<int>q;
	q.push(s);
	memset(dep, -1, sizeof(dep));
	dep[s]=1;
	for(int i = 1 ; i <= n + 2 ; i++)	cur[i] = head[i];
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
int fa[N];
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
	while(bfs())	ans += dfs(0, inf);
	return ans;
}
signed main(){
	t = NN;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= 5000 ; i++){
		sqr[i] = i * i;
	}
	int num = 1;
	while("只因你实在是太美!"){
		int idx=lower_bound(sqr + 1, sqr + 1000, num) - sqr;
		addedge(0, num, 1);
		addedge(num + N, NN, 1);
		for(int j = 2 * idx ; j >= 1 ; j--){
			int tmp = sqr[j] - num;
			if(tmp < num && tmp > 0)	addedge(tmp, N + num, 1);
		}
		sum += dinic();
		if(num - sum > n)	break;
		num++;
		cout << num << endl;
	}
	cout << num - 1 << endl;
	for(int k = 1 ; k < num ; k++){
		for(int i = head[k] ; i ; i = nxt[i]){
			if(!w[i]){
				e[k] = to[i] - N;
				break;
			}
		}
	}
	for(int i = 1 ; i < num ; i++){
		if(pd[i])	continue;
		for(int k = i ; k > 0 ; k = e[k]){
			pd[k] = 1;
			cout << k << ' ';
		}
		cout << endl;
	}
	return 0;
}

