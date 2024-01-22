/*************************************************************************
	> File Name: P2756飞行员.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月07日 星期一 20时15分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int head[N], to[N], w[N], nxt[N];
void add(int u, int v, int ww){
	static int cnt = 1;
	to[++cnt] = v;
	w[cnt] = ww;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int vis[N], pre[N], num[N];
bool bfs(int s){
	memset(vis, 0, sizeof(vis));
	memset(pre, 0, sizeof(pre));
	memset(num, 0, sizeof(num));
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(!w[i] || vis[v])	continue;
			num[v] = u;
			pre[v] = i;
			vis[v] = true;
			if(v == n + 2)	return true;
			q.push(v);
		}
	}
	return false;
}
void EK(int s){
	int ans = 0;
	while(bfs(s)){
		ans++;
		for(int i = n + 2; i ; i = num[i]){
			int edge = pre[i];
			w[edge] = 0;
			w[edge^1] = 1;
		}
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	int u, v;
	cin >> u >> v;
	while(u != -1){
		add(u, v, 1);
		add(v, u, 0);
		cin >> u >> v;
	}
	//cout << 6 << endl;
	for(int i = 1 ; i <= m ; i++){
		add(n + 1, i, 1);
		add(i, n + 1, 0);
	}
	for(int i = m + 1 ; i <= n ; i++){
		add(i, n + 2, 1);
		add(n + 2, i, 0);
	}
	EK(n + 1);
	for(int i = 1 ; i <= m ; i++){
		for(int j = head[i] ; j ; j = nxt[j]){
			if(!w[j] && to[j] != n + 1){
				cout << i << ' ' << to[j] << endl;
			}
		}
	}
	return 0;
}
