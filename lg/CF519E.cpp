#include<bits/stdc++.h>
using namespace std;
//#define int long long 
const int N = 2e6 + 10;
int to[N], nxt[N], head[N];
void add(int u, int v){
	static int cnt = 0;
	to[++cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt;
}
int n, m, s;
int dp[2000000+10][25] ,dep[2000000+10],sum=0;
int siz[N];
void getdp(int now,int father){
	dp[now][0]=father;
	dep[now]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[now];i++){
		dp[now][i]=dp[dp[now][i-1]][i-1];
	}
	for(int i = head[now] ; i ; i = nxt[i]){
		if(to[i] != father) getdp(to[i], now), siz[now] += siz[to[i]];
	}
	siz[now]++;
//	for(int i=head[now];i;i=e[i].nxt){
//		if(e[i].to!=father)	getdp(e[i].to,now);
//	}
}
int lca(int a,int b){
	if(dep[a]<dep[b]){
		swap(a,b);
	}
	for(int i=23;i>=0;i--){
		if(dep[a]-(1<<i)>=dep[b])	a=dp[a][i];
	}
	if(a==b){
		return b;
	}
	for(int i=23;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i],b=dp[b][i];
		}
	}
	return dp[b][0];
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	s = 1;
	for(int i = 1 ; i < n ; i++){
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	cin >> m;
	getdp(1, 0);
	for(int i = 1 ; i <= m ; i++){
		int a, b;
		cin >> a >> b;
		if(a == b){
			cout << siz[1] << endl;
			continue;
		}
		int tmp = lca(a, b);
		int disa = dep[a] - dep[tmp];
		int disb = dep[b] - dep[tmp];
		if(disa == disb){
			for(int i = 21 ; i >= 0 ; i--){
				if(dep[a] - (1 << i) > dep[tmp]){
					a = dp[a][i];
					b = dp[b][i];
				}
			}
			cout << siz[1] - siz[a] - siz[b] << endl;
		}
		else{
			if((disa + disb) % 2 != 0)	cout << 0 << endl;
			else{
				int dis = disa + disb;
				if(disa < disb)	swap(disa, disb), swap(a, b);
				int mdep = dep[a] - dis / 2;
				int x = a;
				//int last = x;
				for(int i = 21 ; i >= 0 ; i--){
					//cout << i << endl;
					if(dep[x] - (1 << i) > mdep)	x = dp[x][i];	
				}
				int tmp = dp[x][0];
				int ans = siz[tmp] - siz[x];
				//if(dep[b] > dep[tmp]){
				//	int xy = b;
				//	for(int i = 21 ; i >= 0 ; i--){
				//		if(dep[xy] - (1 << i) > mdep)	xy = dp[xy][i];
				//	}
				//	ans -= siz[xy];
				//}
				cout << ans << endl;
				
			}
		}
	}
	return 0;
}
