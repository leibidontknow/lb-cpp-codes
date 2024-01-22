#include<bits/stdc++.h> 
using namespace std;
int T, n, q;
int f(char ch){
	if(ch >= '0' && ch <= '9')	return ch - '0';
	if(ch >= 'a' && ch <= 'z')	return ch - 'a' + 10;
	return ch - 'A' + 37;
}
struct Tree{
	int son[65];
	int &operator[](int idx){
		return son[idx];
	}
	const int &operator[](int idx)const{
		return son[idx];
	}
	int cnt;
}t[3000000 + 10];
int idx = 0;
void insert(char *str){
	int now = 0;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i]; 
		if(!t[now].son[f(ch)])	t[now].son[f(ch)] = ++idx;
		now = t[now].son[f(ch)];
		t[now].cnt++;
	}
}
int query(char *str){
	int now =0;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i];
		if(!t[now][f(ch)])	return 0;
		now = t[now][f(ch)];
	}
	return t[now].cnt;
}
char str[3000000 + 10];
void clear(int now){
	t[now].cnt = 0;
	for(int i = 0 ; i < 65 ; i++){
		if(t[now][i])	clear(t[now][i]), t[now][i] = 0;
	}
}
void solve(){
	idx = 0;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)	cin >> str, insert(str);
	for(int i = 1 ; i <= q ; i++){
		cin >> str;
		cout << query(str) << endl;
	}
	clear(0);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)	solve();
	return 0;
}