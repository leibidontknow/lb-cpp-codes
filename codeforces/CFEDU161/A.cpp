#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
int n;
string a, b, c; 
void solve(){
	cin >> n; 
	cin >> a >> b >> c;
	bool flag = false;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == c[i] || b[i] == c[i]){
			flag = flag;
		}	
		else{
			flag = true;
		}
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}