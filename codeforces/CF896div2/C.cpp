/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t;
int n, m;
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(m == 1){
			cout << 0 << endl;
			for(int i = 1 ; i <= n ; i++){
				cout << 0 << endl;
			}
			continue;
		}
		vector<vector<int> > vec(n + 1, vector<int>(m + 1));
		if(n >= m - 1){
			cout << m << endl;
			for(int i = 0 ; i < m ; i++){
				for(int j = 0 ; j < min(n, m - 1); j++){
					vec[j][i] = (i + 1 + j) % m;
				}
			}
			if(n > m - 1){
				for(int i = m - 1 ; i < n ; i++){
					for(int j = 0 ; j < m ; j++ ){
						vec[i][j] = (j + 1) % m;
					}
				}
			}
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++){
					cout << vec[i][j] << ' ';
				}
				cout << endl;
			}
		}
		else{
			cout << n + 1 << endl;
			for(int i = 0 ; i < n + 1 ; i++){
				for(int j = 0 ; j < n ; j++){
					vec[j][i] = (i + j + 1) % (n + 1);
				}
			}
			for(int i = 0 ; i < n ; i++){
				for(int j = n + 1 ; j < m ; j++){
					vec[i][j] = j;
				}
			}
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++){
					cout << vec[i][j] << ' ';
				}
				cout << endl;
			}
		}
	}
	return 0;
}
