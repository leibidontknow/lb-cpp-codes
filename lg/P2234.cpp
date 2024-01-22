#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, gz;
int modi = 0;
const int N = 2e6 + 10;
int mems = 0;
struct node{
	int val;
	int ls, rs;
	int pri, size;
	node(){}
	node(int val, int ls, int rs, int pri, int size):val(val), ls(ls), rs(rs), pri(pri), size(size){}
}t[N];
int cnt, root;
void update(int idx){
	t[idx].size = t[t[idx].ls].size + t[t[idx].rs].size + 1;
}
int newnode(int x){
	t[++cnt] = node(x, 0, 0, rand(), 1);
	return cnt;
}
void split(int idx, int x, int &L, int &R){
	if(!idx){
		L = R = 0;
		return;
	}
	if(t[idx].val <= x){
		L = idx;
		split(t[idx].rs, x, t[idx].rs, R);
	}
	else{
		R = idx;
		split(t[idx].ls, x, L, t[idx].ls);
	}
	update(idx);
}
int merge(int l, int r){
	if(!l || !r)	return l + r;
	if(t[l].pri > t[r].pri){
		t[l].rs = merge(t[l].rs, r);
		update(l);
		return l;
	}
	else{
		t[r].ls = merge(l, t[r].ls);
		update(r);
		return r;
	}
}
int ans = 0;
void insert(int x){
	if(x - modi < gz)	return;
	mems++;
	int l, r;
	x -= modi;
	split(root, x - 1, l, r);
	root = merge(merge(l, newnode(x)), r);
}
void change(int &idx, int x){
	if(!idx)
		return;
	if(t[idx].val + modi < gz){
		// cout << "DEBUG" << idx << ' ' << t[idx].val << endl;
		ans += t[idx].size - t[t[idx].rs].size;
		idx = t[idx].rs;
		update(idx);
		change(idx, x);
		update(idx);
		return;
	}
	change(t[idx].ls, x);
	update(idx);
}
int kth(int idx, int k){
	if(idx == 0)	return -1;
	if(k == t[idx].size - t[t[idx].rs].size)	return idx;
	if(k < t[idx].size - t[t[idx].rs].size)	return kth(t[idx].ls, k);
	return kth(t[idx].rs, k - t[t[idx].ls].size - t[t[idx].rs].size);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> gz;
	for(int i = 1 ; i <= n ; i++){
		char opt;
		int x;
		cin >> opt >> x;
		if(opt == 'I')	insert(x);
		if(opt == 'A')	modi += x, change(root, x);
		if(opt == 'S')	modi -= x, change(root, -x);
		if(opt == 'F'){
			if(kth(root, mems - ans - x + 1) == -1){
				cout << -1 << endl;
			}
			else{
				// cout << mems << endl;
				// cout << t[root].size << endl;
				cout << t[kth(root, mems - ans - x + 1)].val + modi << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}