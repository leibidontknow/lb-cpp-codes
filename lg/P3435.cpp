#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s1, s2;
int fail[2000000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	int lenb = s2.length();
	fail[0] = -1;
	int j = -1;
	for(int i = 0 ; i < lenb ; i++){
		//cout << (s2[i + 1] == s2[j + 1]) << endl;
		while(~j && s2[j + 1] != s2[i + 1])	j = fail[j];
		if(s2[j + 1] == s2[i + 1])	j++;
		fail[i + 1] = j;
	}
	int ans = 0;
	for(int i = 1 ; i < lenb ; i++){
		if(fail[i] == -1)	continue;
		int j = i;
		while(~fail[j])	j = fail[j];
		fail[i] = j;
		ans += i - j;
	}
	cout << ans << endl;
	return 0;
} 
