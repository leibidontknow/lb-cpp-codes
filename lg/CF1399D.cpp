/*************************************************************************
	> File Name: CF1399D.cpp
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
int n;
string s;
int bh[1919810];
signed main(){
	cin >> n;
	cin >> s;
	for(int i = 0 ; i <= n ; i++)	bh[i] = 0;

	int idx = 0;
		priority_queue<int, vector<int>, greater<int> >q1, q2;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){
				if(q1.empty()){
					q2.push (++idx);
					bh[i] = idx;
				}
				else{
					q2.push( q1.top());
					bh[i] = q1.top();
					q1.pop();
				}
			}
			else{
				if(q2.empty()){
					q1.push(++idx);
					bh[i] = idx;
				}
				else{
					q1.push(q2.top());
					bh[i] = q2.top();
					q2.pop();
				}
			}
		}
		cout << idx << endl;
		for(int i = 0 ; i < n ; i++){
			cout << bh[i] << ' ';
		}
		cout << endl;
	
	while(--t > 0)	main();
    return 0;
}
