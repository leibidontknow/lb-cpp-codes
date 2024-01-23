#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N = 2e6 + 10;
int n;
void ABS(int &x){
	x = abs(x);
}
template<typename... Args>
void ABS(int &x, Args& ...args){
	ABS(x);
	ABS(args...);
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n; 
	cout << "YES" << endl;
	for(int i = 1 ; i <= n ; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ABS(x1, x2, y1, y2);
		if((x1 & 1) && (y1 & 1)){
			cout << 1 << endl;
		}
		else if((x1 & 1) && !(y1 & 1)){
			cout << 2 << endl;
		}
		else if(!(x1 & 1) && (y1 & 1)){
			cout << 3 << endl;
		}
		else{
			cout << 4 << endl;
		}
	}
	return 0;
}