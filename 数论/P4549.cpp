/*************************************************************************
	> File Name: P4549.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
int a[1919810];
signed main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >>a[i];
		a[i] = abs(a[i]);
		if(i >= 2){
			a[i] = __gcd(a[i - 1], a[i]);
		}
	}
	cout << a[n] << endl;
	return 0;
}
