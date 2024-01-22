/*************************************************************************
	> File Name: test.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i = 0 ; i <= 100 ; i++){
		int xorsum = 0;
		for(int j = 0 ; j <= i ; j++){
			xorsum ^= j;
		}
		cout << i << ':' << xorsum << endl;
	}
	return 0;
}
