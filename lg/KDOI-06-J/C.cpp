#include<bits/stdc++.h> 
using namespace std;
long long n, k;
int read(){
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))	ch = getchar();
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
long long  tmp;
int ans;
long long  ex = 1;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, bool> mp;
int main(){
	n = read();
	k = read();
	for(int i = 1 ; i <= n ; i++)	ex *= n; 
	for(int i = 0 ; i < k ; i += n){
		for(int j = i ; j <= ex ; j += k){
			if(j % 10 == n && !mp[j]){
				mp[j] = 1;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}