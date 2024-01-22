#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int n, k, a[N];
int ans;
int mina = 3;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> k; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	if(n <= 100 || mina >= 2){
		for(int i = 1 ; i <= n ; i++){
			int sum = 0, csum = 1;
			for(int j = i ; j <= n ; j++){
				sum += a[j];
				csum *= a[j];
				if(sum * k == csum){
					ans++;
					if(k >= 2)
						break;
				}
			}
		}
	}
	else{
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == 1){
				ans = ans * 2 + 1;
			}
		}
		cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}