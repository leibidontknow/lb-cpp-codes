#include<bits/stdc++.h> 
using namespace std;
#define int long long 
string s;
const int N = 20;
int dp[N][N];
int ans[N][N];
const int INF = 0x3f3f3f3f;
int f(int x, int y){
	if(x < y)
		x += 10;
	return x - y;
}
int add(int x, int y){
	return (x + y) % 10;
}
int a[2000000 + 20];
signed main(){
	ios::sync_with_stdio(false);
	cin >> s; 
	for(int i = 0 ; i < s.size() ; i++){
		a[i + 1] = s[i] - '0';
	}
	int len = s.size();
	for(int x = 0 ; x <= 9 ; x++){
		for(int y = 0 ; y <= 9 ; y++){
			for(int i = 0 ; i < 10 ; i++){
				for(int j = 0 ; j < 10 ; j++)
					dp[i][j] = INF;
			}
			for(int i = 0 ; i < 10 ; i++){
				dp[i][add(i, x)] = 1;
				dp[i][add(i, y)] = 1;
			}
			for(int k = 0 ; k < 10 ; k++){
				for(int i = 0 ; i < 10 ; i++){
					for(int j = 0 ; j < 10 ; j++){
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
					}
				}
			}
			for(int i = 1 ; i < len ; i++){
					ans[x][y] += dp[a[i]][a[i + 1]] - 1;
					if(ans[x][y] >= INF)
						ans[x][y] = INF;
			};
			// if(x == 4 && y == 2){
			// 	for(int i = 0 ; i < 10 ; i++){
			// 		cout << i << ":";
			// 		for(int j = 0 ; j < 10 ; j++){
			// 			cout << j << ',' << dp[i][j] << ' ';
			// 		}
			// 		cout << endl;
			// 	}
			// }
		}
	}
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if(ans[i][j] >= 1e9)
				ans[i][j] = -1;
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
