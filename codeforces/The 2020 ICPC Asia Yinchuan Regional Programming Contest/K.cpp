#include<bits/stdc++.h> 
using namespace std;
int T, n, q;
int f(char ch){
	if(ch >= 'a' && ch <= 'z')	return ch - 'a';
	if(ch == '.')	return 27;
	if(ch == '/')	return 28;
	return 0;
}
struct Tree{
	int son[35];
	int &operator[](int idx){
		return son[idx];
	}
	const int &operator[](int idx)const{
		return son[idx];
	}
	int cnt;
	bool is;
	bool endis;
}t[3000000 + 10];
int idx = 0;
void insert(char *str){
	int now = 0;
	t[now].cnt++;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i]; 
		if(!t[now].son[f(ch)])	t[now].son[f(ch)] = ++idx;
		now = t[now].son[f(ch)];
		t[now].cnt++;
	}
}
void desert(char *str){
	int now = 0;
	t[now].cnt--;
	for(int i = 0 ; str[i] ; i++){
		char ch = str[i];
		now = t[now].son[f(ch)];
		t[now].cnt--;
	}
}
int query(char *str){
	int now = 0;
	int i;
	for(i = 0 ; str[i] ; i++){
		char ch = str[i];
		now = t[now][f(ch)];
		if(t[now].cnt < 1 && t[now].is == 1){
			t[now].endis = 1;
			return 0;
		}
		if(t[now].cnt < 1 && t[now].endis == 1){
			return -1;
		}
		t[now].is = 1;
		if(t[now].cnt < 1)	return t[now].endis = 1;
	}
	return 1;
}
char str[50000 + 10][51];
void solve(){
	idx = 0;
	cin >> n;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)	cin >> str[i], insert(str[i]);
	for(int i = 1 ; i <= n ; i++){
		desert(str[i]);
		ans += query(str[i]);
		cout << ans << endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	T = 1;
	while(T--)	solve();
	return 0;
}