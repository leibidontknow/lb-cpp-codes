/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n;
double p[1919810], x[1919810], sum[1919810];
int main(){
	cin >> n;
	for(int i = 1; i <= n ; i++){
		cin >> p[i];
	}
	for(int i = 1 ; i <= n ; i++){
		x[i] = (1 - p[i]) / p[i] * sum[i - 1] + 1 / p[i];
		sum[i] = sum[i - 1] + x[i];
	}
	cout << fixed << setprecision(20) << sum[n] << endl;
	return 0;
}
