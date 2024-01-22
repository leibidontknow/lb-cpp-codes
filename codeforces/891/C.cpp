/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月08日 星期二 00时03分59秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1919810];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1 ; i <= n * (n-1) / 2 ; i++){
			cin >> a[i]; 
		}
		sort(a + 1, a + 1 + (n * (n - 1) / 2));
		int tmp=(n-1);
		int i = 1;
		while(tmp>0){
			cout << a[i] << ' ';
			i += tmp;
			tmp--;
		}
		cout << a[n * (n-1) / 2]  << endl;
	}
	return 0;
}
