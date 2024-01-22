/*************************************************************************
	> File Name: E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, a[N], b, h[N], l[N], r[N];
long double v[2*N], t[2*N], ans, tmp, z;
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> h[i] >> l[i] >> r[i];
		a[i] += 1000000;
	}
	for(int i = 1 ; i <= m ; i++){
		cin >> b >> z;
		b += 1000000;
		v[b] += z;
	}
	for(int i = 1 ; i <= n ; i++){
		int pos = a[i] - h[i];
	}
}
