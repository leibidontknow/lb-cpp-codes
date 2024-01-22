#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e6 + 10;
int n, q, a[N], tmp[N];
int tot, id[N], l[N], r[N], tag[N];
int siz;
void Sort(int block){
	for(int i = l[block] ; i <= r[block] ; i++)
		tmp[i] = a[i];
	sort(tmp + l[block], tmp + r[block] + 1);
}
void init(){
	tot = sqrt((double)n);
	siz = sqrt((double)n);
	if(n % tot)	tot++;
	for(int i = 1 ; i <= tot ; i++){
		l[i] = (i - 1) * siz + 1;
		r[i] = i * siz;
	}
	r[tot] = n;
	for(int i = 1 ; i <= tot ; i++){
		for(int j = l[i] ; j <= r[i] ; j++){
			id[j] = i;
		}
	}
	for(int i = 1 ; i <= tot ; i++)
		Sort(i);
}
void update(int from, int to, int val){
	int x = id[from], y = id[to];
	if(x == y){
		for(int i = from ; i <= to ; i++)
			a[i] += val;
		Sort(x);
		return;
	}
	for(int i = from ; i <= r[x] ; i++)
		a[i] += val;
	for(int i = l[y] ; i <= to ; i++)
		a[i] += val;
	for(int i = x + 1 ; i < y ; i++)
		tag[i] += val;
	Sort(x);
	Sort(y);
}
int query(int from, int to, int c){
	int ans = 0;
	int x = id[from], y = id[to];
	if(x == y){
		for(int i = from ; i <= to ; i++){
			if(a[i] + tag[x] >= c)
				ans++;
		}
		return ans;
	}
	for(int i = from ; i <= r[x] ; i++)
		if(a[i] + tag[x] >= c)
			ans++;
	for(int i = l[y] ; i <= to ; i++)
		if(a[i] + tag[y] >= c)
			ans++;
	for(int i = x + 1 ; i < y ; i++){
		ans += r[i] - (lower_bound(tmp + l[i], tmp + r[i] + 1, c - tag[i]) - tmp) + 1;		
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	init();
	for(int i = 1 ; i <= q ; i++){
		char opt;
		cin >> opt;
		int a, b, c;
		cin >> a >> b >> c;
		if(opt == 'M')	update(a, b, c);
		else cout << query(a, b, c) << endl;
	}
	return 0;
}