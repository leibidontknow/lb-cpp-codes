#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
string t, s[6919810];
struct node{
	int x, idx;
	bool operator<(const node &b)const{
		return x < b.x;
	}
};
node a[6919810], b[6919810];
int bb[6919810];
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> t;
	for(int i = 1 ; i <= n ; i++)	cin >> s[i];
	for(int i = 1 ; i <= n ; i++){
		int p1 = 0, p2 = 0;
		while(p1 < s[i].length() && p2 < t.length()){
			if(s[i][p1] == t[p2])	p1++, p2++;
			else p1++;
		}
		int pre = p2;
		p1 = s[i].length() - 1;
		p2 = t.length() - 1;
		while(p1 >= 0 && p2 >= 0){
			if(s[i][p1] == t[p2])	p1--, p2--;
			else p1--;
		}
		int nxt = t.length() - p2 - 1;
		a[i].x = pre;
		b[i].x = nxt;
	}
	sort(b + 1, b + 1 + n);
	for(int i = 1 ; i <= n ; i++)	bb[i] = b[i].x;
		int siz = t.length();
	for(int i = 1 ; i <= n ; i++){
		int tmp = n - (lower_bound(bb + 1, bb + 1 + n, siz - a[i].x) - bb) + 1;
		ans += tmp > 0 ? tmp : 0;
	}
	cout << ans << endl;
	return 0;
}