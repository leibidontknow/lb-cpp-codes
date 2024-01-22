/*************************************************************************
	> File Name: A.cpp
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
signed main(){
	int n, k, x;
	cin >> n >> k >> x;
	if(k > n || k - 1 > x) puts("-1");
	else{
		int sum = 0;
		sum += (k - 1) * k / 2;
		int tmp = n - k;
		if(x == k) x--;
		sum += tmp * x;
		cout << sum << endl;
	}
    while(--t > 0)	main();
    return 0;
}
