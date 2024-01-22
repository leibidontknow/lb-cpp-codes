#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	while(n % 2 == 0){
		n /= 2;
	}
	while(n % 3 == 0){
		n /= 3;
	}
	if(n != 1){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
	return 0;
}