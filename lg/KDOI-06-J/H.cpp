#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int k, n, a[2000000 + 10];
vector<int> sub[200000 + 10];
int score[2000000 + 10];
unordered_map<int, int> mp;
signed main(){
	ios::sync_with_stdio(false);
	cin >> k; 
	for(int i = 1 ; i <= k ; i++){
		int p;
		cin >> p; 
		while(p--){
			int x;
			cin >> x;
			sub[i].push_back(x);
		}
		cin >> p;
		score[i] = p;
	}
	cin >> n; 
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i <= k ; i++){
		int tmp = a[sub[i][0]];
		bool flag = false;
		for(int v : sub[i]){
			if(a[v] != tmp){
				flag = true;
				break;
			}
		}
		if(flag)
			continue;
		mp[tmp] += score[i];
	}
	int maxx = 0;
	int maxi = 0;
	for(int i = 1 ; i <= n ; i++){
		if(mp[a[i]] > maxx){
			maxx = mp[a[i]];
			maxi = a[i];
		}
	}
	cout << maxx << endl << maxi << endl;
	return 0;
}