/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
double ans;
int T, n, m;
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n >> m;
		for(double i = 1 ; i <= m ; i += 1)	ans += (pow(i / m, n) - pow((i - 1) / m, n)) * i;
		cout << fixed << setprecision(20) << ans << endl;
	}
}
