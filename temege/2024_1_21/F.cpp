#include<bits/stdc++.h> 
using namespace std;
#define int long long 
string s; 
int ans;
int n;
signed main(){
	ios::sync_with_stdio(false);
	cin >> s; 
	s = "0" + s; 
	n = s.length() - 1;
	ans = (n + 1) * n / 2;
	for(int l = 1 ; l <= n ; l++){
		for(int r = l ; r <= l + 12 && r <= n ; r++){
			bool flag = false;
			for(int x = l ; x <= r ; x++){
				for(int k = 1 ; x + 2 * k <= r ; k++){
					if(s[x] == s[x + k] && s[x + k] == s[x + 2 * k]){
						flag = true;
						goto done;
					}
				}
			}
			done:;
			if(!flag)
				ans--;
		}
	}
	cout << ans << endl;
	return 0;
}