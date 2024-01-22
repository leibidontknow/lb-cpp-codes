/*************************************************************************
	> File Name: G.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m, a[200000 + 10], b[200000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)	cin >> a[i];
	for(int i = 1 ; i <= m ; i++)	cin >> b[i];
	int ans = 0;
	for(int i = 1 ; i < n ; i++)	ans += abs(a[i] - a[i + 1]);
	for(int i = 1 ; i < m ; i++)	ans += abs(b[i] - b[i + 1]);
	cout << ans << endl;
	return 0;
}
