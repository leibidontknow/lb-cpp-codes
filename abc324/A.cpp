#include<bits/stdc++.h>
using namespace std;
int n, a[1919810];
int main(){
	cin >> n;
	int tmp = 0;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		if(i == 1){
			tmp = x;
		}
		if(x != tmp){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}