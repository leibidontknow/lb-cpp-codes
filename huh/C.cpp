#include<bits/stdc++.h> 
using namespace std;
#define int long long 
string s;
int n;  
int ans = 0;
string anss;
bool flag[2000 + 10];
void dfs(int pos, int lnum, int lsum, int rnum, int rsum){
	if(pos >= n){
		if(abs(lnum - rnum) <= 1 && abs(lsum - rsum) % 11 == 0){
			vector<char> ll, rr;
			for(int i = 0 ; i < pos ; i++){
				if(flag[i]){
					ll.push_back(s[i]);
				}
				else{
					rr.push_back(s[i]);
				}
			}
			int tmpp = 0;
			sort(ll.begin(), ll.end(), greater<char>());
			sort(rr.begin(), rr.end(), greater<char>());
			if(lnum == rnum){
				if(ll[0] > rr[0]){
					for(int i = 1 ; i + i <= n ; i++){
						tmpp = tmpp * 10 + ll[i - 1] - '0';
						tmpp = tmpp * 10 + rr[i - 1] - '0';
					}
				}
				else{
					for(int i = 1 ; i + i <= n ; i++){
						tmpp = tmpp * 10 + rr[i - 1] - '0';
						tmpp = tmpp * 10 + ll[i - 1] - '0';
					}
				}
			}
			else if(lnum < rnum){
				tmpp = rr[0] - '0';
				for(int i = 1 ; i + i <= n ; i++){
					tmpp = tmpp * 10 + ll[i - 1] - '0';
					tmpp = tmpp * 10 + rr[i] - '0';
				}
			}
			else{
				tmpp += ll[0] - '0';
				for(int i = 1 ; i + i <= n ; i++){
					tmpp = tmpp * 10 + rr[i - 1] - '0';
					tmpp = tmpp * 10 + ll[i] - '0';
				}
			}
			if(tmpp > ans){
				ans = tmpp;
			}
		}
		return;
	}
	flag[pos] = 1;
	dfs(pos + 1, lnum + 1, lsum + s[pos] - '0', rnum, rsum);
	flag[pos] = 0;
	dfs(pos + 1, lnum, lsum, rnum + 1, rsum + s[pos] - '0');
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> s; 
	n = s.size();
	dfs(0, 0, 0, 0, 0);
	cout << ans << endl;
	return 0;
}