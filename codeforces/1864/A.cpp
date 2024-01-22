/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int getsum(int n){
	return (1 + n) * n / 2;
}
int T, x, y, n;
signed main(){
	cin >> T;
	while(T--){
		cin >> x >> y >> n;
		if(y - x < getsum(n - 1)){
			puts("-1");
			continue;
		}
		else{
			int tmp = y - getsum(n - 2);
			cout << x << ' ';
			cout << tmp << ' ';
			int p = tmp;
			tmp = n - 2;
			for(int i = 3 ; i <= n ; i++){
				p += tmp;
				tmp--;
				cout << p << ' ';
			}
			putchar('\n');
		}
	}
	return 0;
}
