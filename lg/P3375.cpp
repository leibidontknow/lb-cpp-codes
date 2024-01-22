/*************************************************************************
	> File Name: P3375.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int fail[2000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	int lena = s1.length();
	int lenb = s2.length();
	s1 = " " + s1;
	s2 = " " + s2;
	fail[0] = fail[1] = 0;
	int j = 0;
	for(int i = 1 ; i < lenb ; i++){
		//cout << (s2[i + 1] == s2[j + 1]) << endl;
		while(j && s2[j + 1] != s2[i + 1])	j = fail[j];
		if(s2[j + 1] == s2[i + 1])	j++;
		fail[i + 1] = j;
	}
	j = 0;
	for(int i = 0 ; i < lena ; i++){
		while(j && s1[i + 1] != s2[j + 1])	j = fail[j];
		if(s1[i + 1] == s2[j + 1])	j++;
		if(j >= lenb){
			cout << i - lenb + 1 << endl;
			j = fail[j];
		}
	}
	for(int i = 1 ; i <= lenb ; i++)	cout << fail[j] << ' ';
	cout << endl;
	return 0;
} 
