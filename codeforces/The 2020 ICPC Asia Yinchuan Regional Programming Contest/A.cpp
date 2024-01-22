#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
const int N = 2000 + 10;
int x[N], y[N], z[N];
typedef pair<int, int> P;
struct num{
	char x;
	int y;
	bool operator<(const num& other) const {
		if(y != other.y)	return y > other.y;
		return x < other.x;
	}
}e[3];
set<P> xx, yy, zz;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i] >> y[i] >> z[i];
		xx.insert(make_pair(y[i], z[i]));
		yy.insert(make_pair(x[i], z[i]));
		zz.insert(make_pair(x[i], y[i]));
	}
	int a = xx.size();
	int b = yy.size();
	int c = zz.size();
	// cout << a << ' ' << b << ' ' << c << endl;
	e[0] = {'X', a};
	e[1] = {'Y', b};
	e[2] = {'Z', c};
	sort(e, e + 3);
	cout << e[0].x << endl;
	return 0;
}