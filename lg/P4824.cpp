#include<bits/stdc++.h>
using namespace std;
string s1, s2;
int fail[2000000 + 10];
bool del[2000000 + 10];
int stk[2000000 + 10];
vector<int> vec;
int lena, lenb;
signed main(){
	ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	lena = s1.length();
	lenb = s2.length();
	s1 = " " + s1;
	s2 = " " + s2;
	fail[0] = fail[1] = 0;
	int j = 0;
	for(int i = 1 ; i < lenb ; i++){
		while(j && s2[j + 1] != s2[i + 1])	j = fail[j];
		if(s2[j + 1] == s2[i + 1])	j++;
		fail[i + 1] = j;
	}
	j = 0;
	int tmppp = 0;
	int top = 0;
	for(int i = 0 ; i < lena ; i++){
		while(j && s1[i + 1] != s2[j + 1])	j = fail[j];
		if(s1[i + 1] == s2[j + 1])	j++;
		stk[++top] = j;
		if(j >= lenb){
			if(tmppp == 0){
				tmppp = i - lenb;
				del[tmppp - 2] = true;
				top -= lenb;
				j = stk[top];
				tmppp = i - lenb - j;
			}
			else{
				del[tmppp] = true;
				top -= lenb;
				j = stk[top];
				tmppp = i - lenb - j;
			}	
		}
	}
	int tmp = 0;
	for(int i = 1 ; i <= lena ; i++){
		cout << del[i];
	}
	cout << endl;
	for(int i = 1 ; i <= lena ; i++){
		if(del[i] == true)	tmp += lenb;
		if(tmp > 0){
			tmp--;
		}
		else{
			cout << s1[i];
		}
	}
	cout << endl;
	return 0;
} 
