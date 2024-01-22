#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 3e5 + 10;
const int M = 2e6 + 10;
int n, q;
int a[N];
int cnt[M], ans[M], siz;
struct query{
	int l, r;
	int id;
	bool operator<(const query &b)const{
		if(l / siz == b.l / siz)	return r < b.r; 
		return l / siz < b.l / siz;
	}
}qry[M];
int res = 0;
void add(int x){
	if(cnt[a[x]] == 0)	res++;
	cnt[a[x]]++;
}
void del(int x){
	if(cnt[a[x]] == 1)	res--;
	cnt[a[x]]--;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	cin >> q;
	siz = max(n / sqrt(q), 1.0);
	for(int i = 1 ; i <= q ; i++){
		cin >> qry[i].l >> qry[i].r;
		qry[i].id = i;
	}
	sort(qry + 1, qry + 1 + q);
	int l = qry[1].l;
	int r = qry[1].r;
	for(int i = l ; i <= r ; i++){
		add(i);
	}
	ans[qry[1].id] = res;
	for(int i = 2 ; i <= q ; i++){
		int id = qry[i].id; 
		while(l > qry[i].l)	
			add(--l);
		while(r < qry[i].r)
			add(++r);
		while(l < qry[i].l)
			del(l++);
		while(r > qry[i].r)
			del(r--);
		ans[id] = res;
	}
	for(int i = 1 ; i <= q ; i++){
		cout << ans[i] << endl;
	}
	return 0;
}