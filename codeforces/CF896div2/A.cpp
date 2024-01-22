/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1919810];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++)	cin >> a[i];
		if(n & 1){
			cout << 4 << endl;
			cout << 1 << ' ' << n - 1 << endl;
			cout << 1 << ' ' << n - 1 << endl;
			cout << n - 1 << ' ' << n << endl;
			cout << n - 1 << ' ' << n << endl;
		}
		else{
			cout << 2 << endl;
			cout << 1 << ' ' << n << endl;
			cout << 1 << ' ' << n << endl;
		}
	}
	return 0;
}
