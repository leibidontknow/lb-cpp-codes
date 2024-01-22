#include<bits/stdc++.h> 
using namespace std;
#define int long long 
#define endl '\n';
int n, m;
int a[2000000 + 10];
struct quan{
	int r, w;
	bool operator<(const quan &b)const{
		return r < b.r;
	}
}q[2000000 + 10];
priority_queue<int, vector<int>, greater<int> > pq;
void solve(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)	
		cin >> a[i];
	for(int i = 1 ; i <= m ; i++){
		cin >> q[i].r >> q[i].w;
	}
	sort(q + 1, q + 1 + m);
	int idx = 1;
	for(int i = 1 ; i <= n ; i++){
		pq.push(a[i]);
		while(idx <= m && q[idx].r == i){
			int tmp = pq.top();
			pq.pop();
			pq.push(tmp - q[idx].w);
			idx++;
		}
	}
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum += pq.top();
		pq.pop();
		cout << sum << ' ';	
	}
	cout << endl;
	pq = {};
}
signed main(){
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)	solve();
	return 0;
}