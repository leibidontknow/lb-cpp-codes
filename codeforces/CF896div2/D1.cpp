/*************************************************************************
	> File Name: D1.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t, n, a[1919810], mid;
int bj[1919810];
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		mid = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)	cin >> a[i], mid += a[i], bj[i] = 0;
		if(mid % n != 0){
			cout << "No" << endl;
			continue;
		}
		mid /= n;

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1, k = 1 ; j <= max(a[i], mid) ; j <<= 1, k++){
				int tmp1 = mid & j; 
				int tmp2 = i & j;
				if(tmp1 ^ tmp2){
					if(tmp1 == 1){ 
						bj[k]++;
					}
					else{
						bj[k]--;
					}
				}
			}
		}
		bool flag = true;
		for(int i = 1 ; i <= n ; i++){
			if(bj[i] != 0){
				cout << "Yes" << endl; 
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "Yes" << endl;
		}
	}
	return 0;
}
