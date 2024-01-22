#include<bits/stdc++.h> 
using namespace std;
#define int unsigned long long 
const int N = 3e6 + 10;
vector<int>a;
unordered_map<int, int>mp;
int cnt[N];
int q; 
int Find(int x){
	return (mp[x] == 0) ? x : mp[x] = Find(mp[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> q; 
	for(int i = 1 ; i <= q ; i++){
		int opt, x, y; 
		cin >> opt;
		if(opt == 1){
			cin >> x;
			a.push_back((x << 18) + cnt[x]);
		}
		else{
			cin >> x >> y; 
			if(x == y)
				continue;
			mp[(x << 18) + cnt[x]] = (y << 18) + cnt[y]; 
			cnt[x]++;
		}
	} 
	for(int v : a){
		if(mp[v] == 0){
			cout << (v >> 18) << ' ';
		}
		else{
			cout << (Find(v) >> 18) << ' ';
		}
	}
	return 0;
}