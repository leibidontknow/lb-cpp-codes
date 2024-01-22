#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 3e6 + 10;
int n, a[N], b[N];
int ans = 0;
int cnt = 0;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n; 
	for(int i = 1 ; i <= n ; i++){
		char ch;
		cin >> ch;
		a[i] = (ch == '1' ? 1 : 0);
	}
	for(int i = 1 ; i <= n ; i++){
		bool flag = false;
		if(i <= n && a[i] == 1){
			cnt++;
			flag = true;
		}
		while(i <= n && a[i] == 1){
			b[cnt]++;
			i++;
		}
		i-= flag;
	}
	int flag1 = 0, flag2 = 0;
	if(a[1] == 1)	flag1 = 1;
	if(a[n] == 1)	flag2 = 1;
	int minn = 0x3f3f3f3f3f3f3f3f;
	int inf = minn;
	for(int i = 1 ; i <= cnt ; i++){
		if((flag1 && i == 1) || (flag2 && i == cnt))
			minn = min(minn, b[i] - 1);
		else
			minn = min(minn, b[i] - 1 >> 1);
	}
	for(int i = 1 ; i <= cnt ; i++){
			ans += ceil(b[i] / 1.0 / (2 * minn + 1));
	}
	cout << ans << endl;
	return 0;
}