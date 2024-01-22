/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		ans = min(ans, abs(0 - x));
	}
	cout << ans << endl;
	return 0;
}
