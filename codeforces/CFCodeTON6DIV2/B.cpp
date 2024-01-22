/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t;
struct __initT{
    __initT(){cin >> t;}
}__initt;
int a[1919810], b[1919810];
signed main(){
	int n, m, xorsum = 0, withsum = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i], xorsum ^= a[i];
	for(int i = 1 ; i <= m ; i++) cin >> b[i], withsum |= b[i];
	if(n & 1){
		cout << xorsum << ' ' << (xorsum | withsum) << endl;
	}
	else{
		cout << (xorsum ^ (xorsum & withsum)) << ' ' << xorsum << endl;
	}
    while(--t > 0)	main();
    return 0;
}
