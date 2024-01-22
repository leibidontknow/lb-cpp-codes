#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e6 + 10;
int n;
int s[N];
int ans;
bool killed[N];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n; 
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i]; 
	} 
	sort(s + 1, s + 1 + n);
	int idx = n / 2;
	for(int i = n ; i >= 1 ; i--){
		if(killed[i])
			continue;
		while(idx > 0 && s[idx] * 2 > s[i]){
			idx--;
		}
		if(idx > 0){
			killed[idx--] = 1;
			ans++;
		}
	}
	cout << n - ans << endl;
	return 0;
}