/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T, a, b, c;
int main(){
	cin >> T;
	while(T--){
		cin >> a >> b >> c;
		double mid = (a + b) / 2.0;
		cout << ceil(fabs(a - mid) / c) << endl;
	}
	return 0;
}
