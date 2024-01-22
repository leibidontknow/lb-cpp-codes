#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n;
string s[200010];
int sum[200010];
int ans = 0;
typedef pair<int, int> P;
unordered_map<int, unordered_map<int,int> >mpj, mpo, nmpj, nmpo;
vector<P> qc;
unordered_map<int, unordered_map<int, bool> >qcm;
int f(int x){
	if(x < 0)	return 0;
	return x;
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i];
		int allsum = 0, presum = 0;
		for(char ch : s[i])	
			allsum += ch - '0';
		sum[i] = allsum;
		if(s[i].length() & 1)	{
			nmpj[sum[i]][s[i].size()]++;
			if(nmpj[sum[i]][s[i].size()] > 1 && !qcm[sum[i]][s[i].size()]){
				qc.push_back(make_pair(sum[i], s[i].size()));
			qcm[sum[i]][s[i].size()] = 1;
			}
		}
		else {
			nmpo[sum[i]][s[i].size()]++;
			if(nmpo[sum[i]][s[i].size()] > 1 && !qcm[sum[i]][s[i].size()]){
				qc.push_back(make_pair(sum[i], s[i].size()));
			qcm[sum[i]][s[i].size()] = 1;
			}
		}
		for(int j = 0 ; j < s[i].size() ; j++){
			// cout << i << ":and" << j << ' ' << allsum - 2 * presum << endl; 
			if(s[i].size() & 1)	mpj[allsum - 2 * presum][s[i].size() - 2 * j]++;
			else mpo[allsum - 2 * presum][s[i].size() - 2 *j]++;
			presum += s[i][j]  - '0';
		}
	}
	// for(int i = 1 ; i <= 10 ; i++){
	// 	for(int len = 1 ; len <= 5 ; len++){
	// 		cout << i << "," << len << ' '<<nmpj[i][len] << ' ' << nmpo[i][len] << endl;
	// 	}
	// }
	for(int i = 1 ; i <= n ; i++){
		if(s[i].size() & 1)	ans += mpj[sum[i]][s[i].size()];
		else ans += mpo[sum[i]][s[i].size()];
		int presum = 0;
		for(int j = s[i].length() - 1 ; j >= 0 ; j--){
			//cout << i << ' ' << j << ':' << sum[i] - 2 * presum << ' ' << (int)s[i].size() - 2 * ((int)s[i].size() - j - 1) <<endl;
			if(s[i].size() & 1){
				ans += nmpj[sum[i] - 2 * presum][(int)s[i].size() - 2 * ((int)s[i].size() - j - 1)];
			}
			else{
				ans += nmpo[sum[i] - 2 * presum][(int)s[i].size() - 2 * ((int)s[i].size() - j - 1)];
			}
			presum += s[i][j] - '0';
		}
		ans--;
		// cout << i << ":" <<ans << endl;
	}
	for(P tmp : qc){
		ans -= nmpj[tmp.first][tmp.second] * f(nmpj[tmp.first][tmp.second] - 1);
		ans -= nmpo[tmp.first][tmp.second] * f(nmpo[tmp.first][tmp.second] - 1);
	}
	cout << ans << endl;
	return 0;
}