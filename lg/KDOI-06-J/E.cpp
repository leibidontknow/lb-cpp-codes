#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
int ans[2000000 + 10][2];
signed main(){
	cin >> n >> m; 
	for(int i = 1 ; i <= n ; i++){
		int tmp = 0;
		int maxx = 0;
		for(int j = 1 ; j <= m ; j++){
			int x;
			cin >> x;
			if(x > maxx){
				maxx = x; 
				ans[i][0] = j; 
				ans[i][1] = tmp; 
			}
			if(x){
				tmp++;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 2 ; j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl; 
	}
	return 0;
}