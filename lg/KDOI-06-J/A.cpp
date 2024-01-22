#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 100 + 10;
int a[N], b[N], t, n;
int nows;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] >> b[i];
		nows += 100 / a[i] * b[i];
	}
	cin >> t;
	if(nows >= t){
		cout << "Already Au." << endl;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){
		if(nows + 100 / a[i] * (a[i] - b[i]) >= t){
			cout << ceil((t - nows) * 1.0 / (100.0 / a[i])) << endl;
		}
		else{
			cout << "NaN" << endl;
		}
	}
	return 0;
}