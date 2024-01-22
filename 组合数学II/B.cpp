/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月08日 星期二 10时17分37秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1e9 + 7;
int n, l, a[30];
string s;
int fastpow(int n,int k){	
	if(k==0)	return 1;
	int tmp=fastpow(n,k/2);
	tmp=tmp*tmp%p;
	if(k&1)	tmp = (tmp * n) % p;
	return tmp;
}
signed main(){
	cin >> n >> l;
	for(int i = 1 ; i < n ; i++){
		cin >> str;
		for(char c : str)	a[i] |= (1 << (c - 'A'));
	}
	for(int s = 1 ; s < (1 << n) ; s++){
		int bit = 0;
		int intersection = (1 << 26) - 1;
		for(int i = 0 ; i < n ; i++){
			if(s & (1 << i)){
				bit++;
				intersection &= a[i];
			}
		}
		int num = 0;
		for(int i = 0 ; i < 26 ; i++){
			if(intersection & (1 << i)){
				num++;
			}
		}
		if(bit % 2 == 1)	ans = (ans + fastpow(num, l)) % p;
		else ans = (ans - fastpow(num, l)) % p;
	}
	cout << (ans + p) % p <<endl;
	return 0;
}
