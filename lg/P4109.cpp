#include<bits/stdc++.h> 
using namespace std;
#define int long long 
int t;
void solve(){
	int a[10], b[10], c[10];
	memset(a, 0x3f, sizeof(a));
	memset(b, 0x3f, sizeof(b));
	memset(c, 0x3f, sizeof(c));
	int A, B;
	cin >> A >> B;
	A--;
	int ida = 0, idb = 0;
	while(A){
		a[++ida] = A % 10;
		A /= 10;
	}
	while(B){
		b[++idb] = B % 10;
		B /= 10;
	}
	int sizea = ida, sizeb = idb;
	if(sizea != sizeb){
		int tmp = sizea;
		if(sizeb - sizea > 1){
			if(a[ida] >= 5)	
				tmp++;
			cout << 5;
			for(int i = 2 ; i <= tmp ; i++)	
				cout << 0;
			cout << endl;
			return;
		}
		if(a[ida] < 5){
			cout << 5;
			for(int i = 2 ; i <= tmp ; i++)
				cout << 0;
		}
		else if(b[idb] >= 5){
			tmp = idb;
			cout << 5;
			for(int i = 2 ; i <= tmp ; i++)
				cout << 0;
		}
		else{
			if(a[ida] == 9){
				cout << 1;
				for(int i = 1 ; i <= tmp ; i++)
					cout << 0;
			}
			else{
				cout << a[ida] + 1;
				for(int i = 2 ; i <= tmp ; i++)
					cout << 0;
			}
		}
		cout << endl;
	}
	else{
		bool flag = 0;
		for(int i = ida ; i >= 1 ; i--){
			if(flag)
				cout << 0;
			else if(a[i] == b[i])
				cout << a[i];
			else{
				if(a[i] < 5 && b[i] >= 5){
					cout << 5;
				}
				else{
					cout << a[i] + 1;
				}
				flag = 1;
			}
		}
		cout << endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
		solve();
	return 0;
}