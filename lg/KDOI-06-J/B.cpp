#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int inf = 2147483647;
bool f(int x){
	return !(x >= -inf && x <= inf); 
}
signed main(){
	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	if(f(x1 * y1) || f(x1 * y2) || f(x2 * y1) || f(x2 * y2)){
		cout << "long long int" << endl;
	}
	else{
		cout << "int" << endl;
	}
	return 0;
}