#include<bits/stdc++.h>
using namespace std;
int m;
struct node{
	int n, s, w, e;
	int d[4];
}e[4000000 + 10];
int mp[2000 + 10][2000 + 10];
bool check(int x, int y){return x >= 1 && x <= m && y >= 1 && y <= m;}
void dfs(int x, int y){
	int u = mp[x][y];
	if(check(x - 1, y) && !mp[x - 1][y]){
		mp[x - 1][y] = e[u].n;
		dfs(x - 1, y);
	}
	if(check(x + 1, y) && !mp[x + 1][y]){
		mp[x + 1][y] = e[u].s;
		dfs(x + 1, y);
	}
	if(check(x, y + 1) && !mp[x][y + 1]){
		mp[x][y + 1] = e[u].e;
		dfs(x, y + 1);
	}
	if(check(x, y - 1) && !mp[x][y - 1]){
		mp[x][y - 1] = e[u].w;
		dfs(x, y - 1);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin >> m;
	for(int i = 1 ; i <= m * m ; i++){
		cin >> e[i].n >> e[i].s >> e[i].w >> e[i].e;
		if(e[i].n == -1 && e[i].w == -1)	mp[1][1] = i;
		else if(e[i].n == -1 && e[i].e == -1)	mp[1][m] = i;
		else if(e[i].s == -1 && e[i].w == -1)	mp[m][1] = i;
		else if(e[i].s == -1 && e[i].e == -1)	mp[m][m] = i;
	}
	dfs(1, 1);
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= m ; j++){
			cout << mp[i][j];
			if(j != m)	cout << ' ';
		}
		cout << endl;
	}
	return 0;
}