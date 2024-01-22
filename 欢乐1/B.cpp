/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
const int N = 2000 + 10;
int X[N][N], Y[N][N];
char mp[N][N];
char gx[5] = {0, 'U', 'L', 'D', 'R'};
char ggx[5] = {0, 'D', 'R', 'U', 'L'};
int dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};
struct P{
	int x, y;
	P(int x, int y):x(x), y(y){}
	P(){}
};
bool check(int i, int j){
	return i >= 1 && i <= n && j >= 1 && j <= n;
}
queue<P> q;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> X[i][j] >> Y[i][j];
			if(X[i][j] == i && Y[i][j] == j){
				q.push(P(i, j));
				mp[i][j] = 'X';
			}
			if(X[i][j] == -1 && q.empty()){
				q.push(P(i, j));
			}
		}
	}
	while(!q.empty()){
		P cur = q.front();
		int x = cur.x;
		int y = cur.y;
		//cout << x << ' ' << y << q.size() << endl;
		q.pop();
		if(X[x][y] == -1){
			if(mp[x][y]){
				for(int i = 1 ; i <= 4 ; i++){
					int xx = x + dx[i];
					int yy = y + dy[i];
					if(check(xx, yy) && X[xx][yy] == -1 && mp[xx][yy] == 0){
						mp[xx][yy] = gx[i];
						q.push(P(xx, yy));
					}
				}
			}
			else{
				for(int i = 1 ; i <= 4 ; i++){
					int xx = x + dx[i];
					int yy = y + dy[i];
					if(check(xx, yy) && X[xx][yy] == -1){
						q.push(P(xx, yy));
						if(!mp[x][y])	mp[x][y] = ggx[i];
						mp[xx][yy] = gx[i];
					}
				}
			}
			continue;
		}
		for(int i = 1 ; i <= 4 ; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(check(xx, yy)){
				if(X[xx][yy] == X[x][y] && Y[xx][yy] == Y[x][y] && !mp[xx][yy]){
					mp[xx][yy] = gx[i];
					q.push(P(xx, yy));
				}
				if(X[xx][yy] == -1 && !mp[xx][yy])	q.push(P(xx, yy));
			}
		}
	}
	bool flag = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(!mp[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}
	if(flag){
		cout << "VALID" << endl;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				cout << mp[i][j];
			}
			cout << endl;
		}
	}
	else cout << "INVALID" << endl;
	return 0;
}
