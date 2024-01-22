#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e5 + 10;
int n, k, a[N];
int ans;
int fail[N];
int maxn;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> k; 
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		maxn += a[i];
	}
	maxn *= k;
	int x;
	x = 0;
	for(int i = n ; i >= 1 ; i--){
		if(a[i] == 1){
			if(x == 0)	x = fail[i] = i;
			else fail[i] = x;
		}
		else
			x = 0;
	}
	for(int i = 1 ; i <= n ; i++){
		int sum = 0, csum = 1;
		for(int j = i ; j <= n ; j++){
			if(fail[j]){
				if(csum % k == 0 && csum / k > sum && csum / k <= sum + fail[j] - j + 1)
					ans++;
				sum += b[j] - j + 1;
				j = fail[j];
				continue;
			}
			sum += a[j];
			csum *= a[j];
			if(sum * k == csum){
				ans++;
			}
			if(csum >= maxn)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}