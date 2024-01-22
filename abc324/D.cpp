#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
string s;
int mp[10];
int ans = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for(int i = 0 ; i < s.length(); i++){
		mp[s[i] - '0']++;
	}
	for(int i = 0 ; i <= 3162277 ; i++){
		int tmp = i * i;
		int siz = 0;
		int tmmp[10];
		memset(tmmp, 0, sizeof(tmmp));
		while(tmp > 0){
			int tmpp = tmp % 10;
			tmp /= 10;
			tmmp[tmpp]++;
			siz++;
		}
		bool flag = true;
		if(tmmp[0] > mp[0])	flag = false;
		for(int i = 1 ; i <= 9 ; i++){
			if(tmmp[i] != mp[i]){
				flag = false;
				break;
			}
		}
		if(flag)	ans++;
	}
	cout << ans << endl;
	return 0;
}