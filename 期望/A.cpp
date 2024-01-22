/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
long long T, n, m, k;
int main(){
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cout << fixed << setprecision(11) << (pow((double)k / m, n) - pow((double)(k - 1) / m, n)) <<endl;
	}
	return 0;
}
