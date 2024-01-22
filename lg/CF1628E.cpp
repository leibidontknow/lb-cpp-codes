/*************************************************************************
	> File Name: CF1628E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
#define int long long 
int n, q;
int to[N], nxt[N], head[N], a[N], b[N];
void add(int u, int v){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int dp[N][2];
vector<int> vec[N];
void dfs(int u, int fa){
	int sum = 0, cnta = 0, cntb = 0;
	for(int i = head[u] ; i ; i = nxt[i]){
		int v = to[i];
		if(v == fa)	continue;
		dfs(v, u);
		if(b[v] == b[u]){
			cnta++;
			vec[u].push_back(dp[v][1] - dp[v][0]);
			sum += dp[v][0];
		}
		else if(b[v] < b[u]){
			cntb++;
			sum += dp[v][1];
		}
		else{
			cnta++;
			sum += dp[v][0];
		}
	}
	sort(vec[u].begin(), vec[u].end());
	for(int i = 0 ; i <= vec[u].size() ; i++){
		dp[u][0] = min(dp[u][0], sum + max(cnta, cntb + (u != 1)) * a[u]);
		dp[u][1] = min(dp[u][1], sum + max(cnta + (u != 1), cntb) * a[u]);
		cnta--;
		cntb++;
		if(i < vec[u].size())	sum += vec[u][i];
	}
}
signed main(){
	ios::sync_with_stdio(false);
	memset(dp, 0x3f, sizeof(dp));
	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i];
	for(int i = 1 ; i <= n ; i++)	cin >> b[i];
	for(int i = 1 ; i < n ; i++){
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	cout << min(dp[1][1], dp[1][0]) << endl;
	return 0;
}
