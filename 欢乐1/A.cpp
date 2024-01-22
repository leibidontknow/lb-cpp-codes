/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m, p[1919810], sum[1919810];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++)	cin >> p[i];
	for(int i = m ; i >= 1 ; i--)	sum[i] = sum[i + 1] + p[i];
	if(sum[1] < n){
		cout << -1 << endl;
		return 0;
	}
	int nowidx = 1;
	for(int i = 1 ; i <= m ; i++){
		if(nowidx + p[i] - 1 > n - sum[i + 1]){
			cout << nowidx << ' ';
			nowidx++;
		}
		else{
			cout << n - sum[i + 1] - p[i] << ' ';
			nowidx = n - sum[i + 1];
		}
	}
	return 0;
}
