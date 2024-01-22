#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, m;
int siz;
const int N = 2e6 + 10;
struct query{
	int id, tim, l, r;  
	bool operator<(const query &b)const{
		if(l / siz != b.l / siz)	return l / siz < b.l / siz;
		if(r / siz != b.r / siz)	return r / siz < b.r / siz;
		return tim < b.tim;
	}
}q[N];
int qcnt, ccnt;
struct modify{
	int idx, x;
}c[N];
int a[N];
int cnt[N], res = 0;
void add(int x){
	if(cnt[x] == 0)	res++;
	cnt[x]++; 
}
int ans[N];
void del(int x){
	if(cnt[x] == 1)	res--;
	cnt[x]--;
}
void modi(int x, int y){
	if(c[x].idx >= q[y].l && c[x].idx <= q[y].r){
		add(c[x].x);
		del(a[c[x].idx]);
	}
	swap(c[x].x, a[c[x].idx]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	siz = pow(n, 0.666);
	for(int i = 1 ; i <= m ; i++){
		char opt;
		int l, r; 
		cin >> opt >> l >> r;
		if(opt == 'Q')

			qcnt++, q[qcnt] = {qcnt, ccnt, l, r};
		else
			ccnt++, c[ccnt] = {l, r};
	}
	sort(q + 1, q + 1 + qcnt);
	int l = 1;
	int r = 0;
	int tim = 0;
	for(int i = 1 ; i <= qcnt ; i++){
		while(l > q[i].l)
			add(a[--l]);
		while(r < q[i].r)
			add(a[++r]);
		while(l < q[i].l)
			del(a[l++]);
		while(r > q[i].r)
			del(a[r--]);
		while(tim < q[i].tim)
			modi(++tim, i);
		while(tim > q[i].tim)
			modi(tim--, i);
		ans[q[i].id] = res; 
	}
	for(int i = 1 ; i <= qcnt ; i++){
		cout << ans[i] << endl;
	}
	return 0;
}