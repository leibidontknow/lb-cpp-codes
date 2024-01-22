/*************************************************************************
	> File Name: D.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月08日 星期二 09时49分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1919810];
int b[1919810];
struct M{
	int minus;
	int idx;
	bool operator<(M b){
		if(minus != b.minus)	return minus > b.minus;
		return idx < b.idx;
	}
}m[1919810];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		for(int i = 1 ; i <= n ; i++){
			cin >> b[i];
			m[i].idx = i;
			m[i].minus = a[i] - b[i];
		}
		sort(m + 1, m + 1 + n);
		int tmp = 1;
		int ans = 0;
		stringstream ss;
		do{
			ss << m[tmp].idx << ' ';
			ans++;
			tmp++;
		}while(tmp <= n && m[tmp].minus == m[tmp - 1].minus);
		cout << ans << endl << ss.str() << endl;
	}
	return 0;
}
