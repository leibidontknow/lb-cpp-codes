#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int n, m;
int maxx, cnt;
const int N = 3e6 + 10;
int a[N], cf[N], id[N], q[N];
int head = 1, tail;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] < maxx)
			continue;
		q[++cnt] = a[i];
		id[cnt] = i; 
		cf[cnt] = q[cnt] - q[cnt - 1];
		maxx = a[i];
	}
	tail = cnt; 
	for(int i = 1 ; i <= m ; i++){
		int x; 
		cin >> x;
		maxx = 0;
		int sum = 0;
		int mid = 0;
		for(int j = head ; j <= cnt ; j++){
			if(q[j] > x){
				mid = j;
				q[j] += cf[j] - (q[j] - x);
				maxx = max(maxx, q[j]);
				break;
			}
			else{
				q[j] += cf[j];
				maxx = max(maxx, q[j]);
			}
		}
		while(mid <= cnt && q[mid] <= maxx)
			mid++;
		maxx = 0;
		for(int j = head ; j < mid ; j++){
			a[id[j]] = q[j];
			if(q[j] < maxx)	continue;
			q[++sum] = q[j];
			id[sum] = id[j];
			cf[sum] = q[sum] - q[sum - 1];
			maxx = max(maxx, q[j]);
		}  
		if(mid < cnt)
			cf[mid] = q[mid] - q[sum];
		for(int j = sum , tmp = 1; j >= 1 ; j--, tmp++){
			q[mid - tmp] = q[j];
			cf[mid - tmp] = cf[j];
			id[mid - tmp] = id[j];
		}
		head = mid - sum;
	}
	maxx = 0;
	for(int i = 1 ; i <= n ; i++){
		cout << a[i] << endl;
	}
	return 0;
}