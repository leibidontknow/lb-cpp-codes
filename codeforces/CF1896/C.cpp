#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
int n, x;
const int N = 2e5 + 10;
struct node{
	int x, id, id2;
}a[N], b[N];
bool cmp(node &a, node &b){
	return a.x < b.x;
}
bool cmp2(node &a, node &b){
	return a.id < b.id;
}
int ans[N];
void solve(){
	cin >> n >> x;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].x;
		a[i].id = i;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> b[i].x;
		b[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + n, cmp);
	for(int i = 1 ; i <= n - x ; i++){
		if(b[i + x].x < a[i].x){
			cout << "NO" << endl;
			return;
		}
		a[i].id2 = i + x;
	}
	for(int i = n - x + 1 ; i <= n ; i++){
		int tmp = i - (n - x);
		if(b[tmp].x >= a[i].x){
			cout << "NO" << endl;
			return;
		}
		a[i].id2 = tmp;
	}
	sort(a + 1, a + 1 + n, cmp2);
	cout << "YES" << endl;
	for(int i = 1 ; i <= n ; i++)
		cout << b[a[i].id2].x << ' ';
	cout << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}