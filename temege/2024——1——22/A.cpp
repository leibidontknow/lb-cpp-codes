#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
const int N = 2e6 + 10;
struct P{
	int idx;
	int typ;
	bool operator<(const P& b)const{
		return idx < b.idx;
	}
}p[N];
int cnt[N];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> p[2 * i - 1].idx;
		cin >> p[2 * i].idx;
		p[2 * i].idx++;
		p[2 * i - 1].typ = 0;
		p[2 * i].typ = 1;
	} 
	sort(p + 1, p + 2 * n + 1);
	int tmp = 0;
	for(int i = 1 ; i <= 2 * n ; i++){
		cnt[tmp] += p[i].idx - p[i - 1].idx;
		if(p[i].typ == 0){
			tmp++;
		}
		else{
			tmp--;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << cnt[i] << ' ';
	} 
	return 0;
}