#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, k;
unordered_map<string, int> mp;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		string s; 
		cin >> s; 
		cin >> mp[s];
	}
	cin.ignore();
	for(int i = 1 ; i <= k ; i++){
		string s; 
		getline(cin, s);
		stack<char>stk;
		string tmp = "";
		string ans = "";
		for(int j = 0 ; j < s.size() ; j++){
			if(s[j] == '{'){
				j++;
				while(s[j] != '}'){
					tmp += s[j];
					j++;
				}
				ans += to_string(mp[tmp]);
				tmp = "";
			}
			else{
				ans += s[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}