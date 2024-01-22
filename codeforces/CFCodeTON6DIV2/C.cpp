/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int t;
struct __initT{
    __initT(){cin >> t;}
}__initt;
int n, k, a[1919810];
signed main(){
	unordered_map<int, int>mp, mp2, mp3;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i], mp2[a[i]]++;
	sort(a + 1, a + 1 + n);
	for(int i = 1 ; i <= n ; i++){
		mp[a[i]] += n - i;
		if(mp3[a[i]] == 0) mp3[a[i]] = i;
		else mp[a[i]] += i - mp3[a[i]] + 1;
	}
	for(int i = 1 ; i <= k ; i++) cout << mp[i] << ' ';
	cout << endl;
    while(--t > 0)	main();
    return 0;
}
