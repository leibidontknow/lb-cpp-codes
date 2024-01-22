/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int main(){
	cin >> T;
	while(T--){
		unordered_map<int, int>mp;
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			int d, s;
			cin >> d >> s;
			if(mp[d] == 0)	mp[d] = s;
			else mp[d] = min(mp[d], s);
		}
		int nwmx = 10000000;
		int ans = 0;
		for(int i = 1 ; ; i++){
			if(i > nwmx)	break;
			ans = i;
			if(mp[i]){
				nwmx = min(nwmx, (mp[i] - 1) / 2 + i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
