#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h> 
using namespace std;
#define int long long 
#define endl '\n'
int t;
const int N = 2e6 + 10;
int a[N];
int n;
int vis[N];
#define MP(a, b) make_pair(a, b)
#define P pair<int, int>
void solve(){
	cin >> n; 
	for(int i = 1 ; i <= 2 * n ; i++){
		cin >> a[i];
		vis[i] = 0;
	}
	sort(a + 1, a + n + 1 + n);
	for(int k = 2 * n - 1 ; k >= 1 ; k--){
		queue<P> ans;
		bool flag = true;
		unordered_map<int, int>mp;
		for(int i = 2 * n ; i >= 1 ; i--){
			if(i != k && !mp[a[i]]){
				mp[a[i]] = i;
			}
			vis[i] = 0;
		}
		vis[k] = 1;
		int x = a[2 * n];
		ans.push(MP(a[2 * n], a[k]));
		for(int i = 2 * n - 1 ; i >= 1 ; i--){
			if(vis[i])
				continue;
			int tmp = mp[x - a[i]];
			if(tmp == i)
				tmp--;
			if(a[tmp] != x - a[i] || tmp < 1){
				flag = false;
				break;
			}
			vis[tmp] = 1;
			mp[x - a[i]]--;
			ans.push(MP(a[i], x - a[i]));
			x = a[i];
		}
		if(flag){
			cout << "YES" << endl;
			cout << a[2 * n] + a[k] << endl;
			while(!ans.empty()){
				cout << ans.front().first << ' ' << ans.front().second << endl;
				ans.pop();
			}
			return;
		}
	}
	cout << "NO" << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}