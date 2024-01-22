#include<bits/stdc++.h> 
using namespace std;
int T, n, q;
int f(char ch){
	return ch - 'a';
}
bitset<1010> cnt[500010];
struct Tree{
	int son[27];
	int &operator[](int idx){
		return son[idx];
	}
	const int &operator[](int idx)const{
		return son[idx];
	}
}t[500000 + 10];
int idx = 0;
void insert(char *str, int num){
	int now = 0;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i]; 
		if(!t[now].son[f(ch)])	t[now].son[f(ch)] = ++idx;
		now = t[now].son[f(ch)];
	}
	cnt[now][num] = 1;
}
void query(char *str){
	int now = 0;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i];
		if(!t[now][f(ch)])	return;
		now = t[now][f(ch)];
	}
	for(int i = 1 ; i <= n ; i++)	if(cnt[now][i])	cout << i << ' ';
}
char str[500000 + 10];
void solve(){
	idx = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int l;
		cin >> l;
		while(l--){
			cin >> str;
			insert(str, i);
		}
	}
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		cin >> str;
		query(str);
		cout << endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}