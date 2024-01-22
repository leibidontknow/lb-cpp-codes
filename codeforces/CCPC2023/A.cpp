#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int n, k;
bool check(int i, int j){
	if(j - i == 1 || j == i || (i == n && j == 1)){
		return false;
	}		
	return true;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int y = 1;
	int sum = 2;
	for(int i = 1 ; i < n ; i++){
		cout << i << ' ' << y << endl;
		y++;
		cout << i << ' ' << y << endl;
		sum += 2;
	}
	cout << n << ' ' << n << endl;
	cout << n << ' ' << 1 << endl;
	if(sum == k)	return 0;
	for(int x = 1 ; x <= n ; x++)
		for(int y = 1 ; y <= n ; y++){
			if(check(x, y)){
				sum++;
				cout << x << ' ' << y << endl;
			}
			if(sum == k)	return 0;
		}
	return 0;
}