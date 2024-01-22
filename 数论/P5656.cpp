/*************************************************************************
	> File Name: P5656.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int exgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int ans = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return ans;
}
signed main(){

}

