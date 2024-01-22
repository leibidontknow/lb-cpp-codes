#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 4e6 + 10;
int n, m, k;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct node{
	int a, w;
	bool operator<(const node &b)const {return w > b.w;}
}t[N];
struct P{
	int siz, h;
	P(){}
	P(int siz, int h):siz(siz), h(h){}
	bool operator<(const P & b)const{
		return h < b.h;
	}
};
int ans = 0, td = INF, fre = 0;
const int maxn=2e6+10;
int sum = 0;
int cnt,root;
struct nod{
	int ls,rs;
	int key,pri;
	int size;
	int sz;
}tree[maxn];
void newt(int x, int sz){
	tree[++cnt].key=x;
	tree[cnt].ls=tree[cnt].rs=0;
	tree[cnt].pri=rand();
	tree[cnt].size=1;
	tree[cnt].sz = sz;
}
void update(int idx){
	tree[idx].size=tree[tree[idx].ls].size+tree[tree[idx].rs].size+1;
}
void split(int idx,int x,int &l,int &r){
	if(idx==0){
		l=r=0;
		return;
	}
	if(tree[idx].key<=x){
		l=idx;
		split(tree[idx].rs,x,tree[idx].rs,r);
	}
	else{
		r=idx;
		split(tree[idx].ls,x,l,tree[idx].ls);
	}
	update(idx);
}
int merge(int l,int r){
	if(l==0||r==0)	return l+r;
	if(tree[l].pri>tree[r].pri){
		tree[l].rs=merge(tree[l].rs,r);
		update(l);
		return l;
	}
	else{
		tree[r].ls=merge(l,tree[r].ls);
		update(r);
		return r;
	}
}
void insert(int x, int sz){
	sum++;
	int l,r;
	split(root,x,l,r);
	newt(x, sz);
	int tmp=merge(l,cnt);
	root=merge(tmp,r);
}
void del(int x){
	sum--;
	int l,r,tmp;
	split(root,x,l,r);
	split(l,x-1,l,tmp);
	tmp=merge(tree[tmp].ls,tree[tmp].rs);
	root=merge(merge(l,tmp),r);
}
int vis[N];
int getbyx(int x, int idx){
	if(tree[idx].key == x){
		return idx;
	}
	if(vis[idx])	return 0;
	vis[idx] = true;
	int tmpp;
	if(x <= tree[idx].key)	{
		tmpp = getbyx(x, tree[idx].ls);
	}
	else{
		tmpp = getbyx(x, tree[idx].rs);
	}
	vis[idx] = false;
	return tmpp;
}
void ist(int szz, int hi){
	if(sum == 0){
		insert(hi, szz);
	}
	else{
		int tmp = getbyx(hi, root);
		if(tree[tmp].key == hi){
			int sz = tree[tmp].sz; 
			del(hi);
			insert(hi, sz + szz);
		}
		else{
			insert(hi, szz);
		}
	}
}
int kth(int idx,int k){
	if(k==tree[tree[idx].ls].size+1)	return idx;
	if(k<=tree[tree[idx].ls].size)	return kth(tree[idx].ls,k);
	if(k>tree[tree[idx].ls].size)	return kth(tree[idx].rs,k-tree[tree[idx].ls].size-1);
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> t[i].w >> t[i].a;
	}
	sort(t + 1, t + 1 + n);
	fre = m;
	for(int i = 1 ; i <= n ; i++){
		// cout << i << endl;
		while(1){
			if(!sum || !t[i].a)
				break;
			int sz = tree[kth(root, sum)].sz;
			int h = tree[kth(root, sum)].key;
			// cout << "pop" << sz << ' ' << h - k << ' ' << t[i].w << endl;
			if(h - k >= t[i].w){
				del(tree[kth(root, sum)].key);
				if(t[i].a < sz){
					ans += t[i].a;
					sz -= t[i].a;
					ist(sz, h);
					ist(t[i].a, t[i].w);
					t[i].a = 0;
				}
				else{
					t[i].a -= sz;
					ans += sz;
					ist(sz, t[i].w);
				}
			}
			else{
				break;
			}
		}
		if(fre && t[i].a){
			if(fre >= t[i].a){
				fre -= t[i].a;
				ans += t[i].a;
				ist(t[i].a, t[i].w);
			}
			else{
				ans += fre;
				ist(fre, t[i].w);
				fre = 0;
			}
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
