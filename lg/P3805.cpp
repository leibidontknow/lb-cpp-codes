#include<bits/stdc++.h>
#define int long long 
using namespace std;
int d[50000000 + 10];
char tmp[50000000 + 10], s[50000000 + 10];
int n, l, r;
signed main(){
	l = r = -1;
	scanf("%s", tmp);
	n = strlen(tmp);
	for(int i = 0 ; i < n ; i++)	s[i * 2 + 1] = tmp[i];
	n = n * 2 + 1;
	for(int i = 0 ; i < n ; i++){
		if(i > r)	d[i] = 1;
		else	d[i] = min(d[l + r - i], r - i + 1);
		while(i - d[i] >= 0 && i + d[i] < n && s[i + d[i]] == s[i - d[i]])	d[i]++;
		if(i + d[i] - 1 > r){
			r = i + d[i] - 1;
			l = i - d[i] + 1;
		}
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++)	ans = max(ans, d[i] - 1);
	cout << ans << endl;
	return 0;
}