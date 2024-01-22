#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct node{
	int val;
	int ls, rs;
	int pri, size;
	int cnt;
	node(){}
	node(int val, int ls, int rs, int pri, int sz):val(val), ls(ls), rs(rs), pri(pri), size(sz), cnt(1){}
}t[N];
int cnt, root; 
int newnode(int x){
	t[++cnt] = node(x, 0, 0, rand(), 1);
	return cnt; 
}
void update(int idx){
	t[idx].size = t[t[idx].ls].size + t[t[idx].rs].size + t[idx].cnt;
}
void zig(int &idx){
	int p = t[idx].ls;
	t[idx].ls = t[p].rs;
	t[p].rs = idx;
	update(idx);
	idx = p;
	update(idx);
}
void zag(int &idx){
	int p = t[idx].rs;
	t[idx].rs = t[p].ls;
	t[p].ls = idx;
	update(idx);
	idx = p;
	update(idx);
}
void build(){
	newnode(INF);
	newnode(-INF);
	root = 1;
	t[root].ls = 2;
	if(t[root].pri < t[t[root].ls].pri)
		zag(root);
}
void insert(int &idx, int x){
	if(!idx){
		newnode(x);
		return;
	}
	if(x == t[idx].val){
		t[idx].cnt++;
		t[idx].size++;
	}
	else{
		if(x < t[idx].val){
			insert(t[idx].ls, x);
			if(t[idx].pri < t[t[idx].ls].pri)
				zig(idx);
		}
		else{
			insert(t[idx].rs, x);
			if(t[idx].pri < t[t[idx].rs].pri)
				zag(idx);
		}
		update(idx);
	}
}
void del(int &idx, int x){
	if(x == t[idx].val){
		if(t[idx].cnt > 1){
			t[idx].cnt--;
			update(idx);
			return;
		}
		if(t[idx].ls || t[idx].rs){
			if(!t[idx].rs || t[idx].ls > t[idx].rs){
				
			}
		}
	}
}