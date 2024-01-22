#include<bits/stdc++.h> 
using namespace std; 
int n;
string T, s[2000000 + 10];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> T;
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i];
	}
	vector<int>vec;
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		// cout << i << endl;
		if(T == s[i]){
			vec.push_back(i), ans++;
			continue;
		}
		if(abs(int(int(s[i].size()) - T.size())) > 1){
			continue;
		}
		if(s[i].size() == T.size()){
			int flag = 0;
			for(int j = 0 ; j < T.size() ; j++){
				if(s[i][j] != T[j]){
					flag++;
				}
			}
			if(flag == 1){
				vec.push_back(i), ans++;
			}
			continue;
		}
		string tmp1, tmp2;
		if(s[i].size() > T.size()){
			tmp1 = s[i];
			tmp2 = T;
		}
		else{
			tmp1 = T;
			tmp2 = s[i];
		}
		int flag = 0;
		int p1 = 0, p2 = 0;
		while(p1 < tmp1.size()){
			if(flag > 1)	break;
			if(tmp1[p1] != tmp2[p2]){
				flag++;
				p1++;
			}
			else{
				p1++;
				p2++;
			}
		}
		if(flag == 1){
			vec.push_back(i);
			ans++;
		}
	}
	cout << ans << endl;
	for(int v : vec){
		cout << v << ' ';
	}
	cout << endl;
	return 0;
}