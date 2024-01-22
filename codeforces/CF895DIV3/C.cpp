/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int check(int x){
	for(int i = 2 ; i * i <= x ; i++){
		if(x % i == 0)	return i;
	}
	return 0;
}
int l, r;
int main(){
	cin >> T;
	while(T--){
		cin >> l >> r;
		if(r < 4){
			puts("-1");
			continue;
		}
		if(l < r || l % 2 == 0){
			int tmp = r >> 1;
			cout << tmp << ' ' << tmp << endl;
			continue;
		}
		int tmp = check(l);
		if(tmp == 0){
			puts("-1");
			continue;
		}
		cout << tmp << ' ' << l - tmp << endl; 
	}
	return 0;
}
