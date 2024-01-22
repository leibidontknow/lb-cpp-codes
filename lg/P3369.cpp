#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
const int N = 2e6 + 10;
struct node{
	int val;
	int ls, rs;
	int pri, size;
	node(){}
	node(int val, int ls, int rs, int pri, int sz):val(val), ls(ls), rs(rs), pri(pri), size(sz){}
}t[N];
int cnt = 0, root = 0;
void update(int idx){
	t[idx].size = t[t[idx].ls].size + t[t[idx].rs].size + 1;
}
int newnode(int x){
	t[++cnt] = node(x, 0, 0, rand(), 1);
	return cnt;
}
void split(int idx, int x, int &L, int &R){
	if(idx == 0){
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
	if(t[l].pri < t[r].pri){
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
void insert(int x){
	int l, r;
	split(root, x, l, r);
	root = merge(merge(l, newnode(x)), r);
}
void del(int x){
	int l, r;
	split(root, x, l, r);
	int p;
	split(l, x - 1, l, p);
	root = merge(merge(l, merge(t[p].ls, t[p].rs)), r);
}
int Rank(int x){
	int l, r; 
	split(root, x - 1, l, r);
	int tmp = t[l].size + 1;
	root = merge(l, r);
	return tmp;
}
int kth(int k, int idx){
	if(t[t[idx].ls].size + 1 == k)	return idx;
	if(t[t[idx].ls].size >= k)	return kth(k, t[idx].ls);
	return kth(k - t[t[idx].ls].size - 1, t[idx].rs);
}
int pre(int x){
	int l, r;
	split(root, x - 1, l, r);
	int tmp = t[kth(t[l].size, l)].val;
	root = merge(l, r);
	return tmp;
}
int nxt(int x){
	int l, r;
	split(root, x, l, r);
	int tmp = t[kth(1, r)].val;
	root = merge(l, r);
	return tmp;
}
signed main(){
	ios::sync_with_stdio(false);
	srand((unsigned)time(NULL));
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int opt, x;
		cin >> opt >> x;
		if(opt == 1)	insert(x);	
		if(opt == 2)	del(x);
		if(opt == 3)	cout << Rank(x) << endl;
		if(opt == 4)	cout << t[kth(x, root)].val << endl;
		if(opt == 5)	cout << pre(x) << endl;
		if(opt == 6)	cout << nxt(x) << endl;
	}
	return 0;
}