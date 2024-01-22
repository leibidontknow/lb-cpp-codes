/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
	cin >> T;
	while(T--){
		cin >> s;
		if(s == "()"){
			puts("NO");
			continue;
		}
		int n = s.length();
		puts("YES");
		bool flag = 0;
		for(int i = 1 ; i < s.length() ; i++){
			if(s[i] == s[i - 1]){
				flag = 1;
				break;
			}
		}
		if(flag){
			for(int i = 1 ; i <= n ; i++){
				putchar('(');
				putchar(')');
			}
		}
		else{
			for(int i = 1 ; i <= n ; i++)	putchar('(');
			for(int i = 1 ; i <= n ; i++)	putchar(')');
		}
		putchar('\n');
	}
	return 0;
}
