/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t, n, x[1919810], y[1919810], k, a, b;
int dis(int i, int j){
	return abs(x[j] - x[i]) + abs(y[j] - y[i]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k >> a >> b;
		for(int i = 1 ; i <= n ; i++)	cin >> x[i] >> y[i];
		if(k == 0){
			cout << dis(a, b) << endl;
			continue;
		}
		int minia = LLONG_MAX;
		int minn = LLONG_MAX;
		for(int i = 1 ; i <= k ; i++){
			if(dis(i, a) < minn){
				minn = dis(i, a);
				minia = i;
			}
		}
		int minib = LLONG_MAX;
		minn = LLONG_MAX;
		for(int i = 1 ; i <= k ; i++){
			if(dis(i, b) < minn){
				minn = dis(i, b);
				minib = i;
			}
		}
		cout << min(dis(a, minia) + dis(b, minib), dis(a, b)) << endl;
	}
	return 0;
}
