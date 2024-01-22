/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T, m, k, a1, ak;
signed main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> m >> k >> a1 >> ak;
		int tmp = m / k;
		if(tmp <= ak){
			cout << max(0ll, (m % k) - a1) << endl;
		}
		else{
			m -= ak * k;
			ak = 0;
			if(a1 >= m) cout << 0 << endl;
			else{
				int ans = 0;
				tmp = m % k;
				m = m - tmp;
				if(a1 >= tmp) a1 -= tmp;
				else ans += tmp - a1, a1 = 0;
				int tmp = a1 / k;
				m -= tmp * k;
				a1 -= tmp * k;
				ans += m / k - 1;
				ans += min(k - a1, 1ll);
				cout << ans << endl;
			}
		}
	}
	return 0;
}
