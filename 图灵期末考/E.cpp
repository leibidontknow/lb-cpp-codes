/*************************************************************************
	> File Name: E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
struct Matrix{
	int x, y;
	vector< vector<double> >a;
	Matrix(int r, int c):x(r), y(c){
		a = vector< vector<double> >(r + 1, vector<double >(c + 1));
	}
	vector<double>& operator[](int i){return a[i];}
    const vector<double>& operator[](int i)const{return a[i];}
	Matrix operator*(const Matrix &b)const{
		Matrix res(x, b.y);
		for(int i = 1 ; i <= x ; i++){
			for(int j = 1 ; j <= b.y ; j++){
				for(int k = 1 ; k <= y ; k++){
					res[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return res;
	}
	Matrix operator*=(const Matrix &b){
		return (*this) = (*this) * b; 
	}
	Matrix pow(int k){
		//Matrix res(x, y);
		//for(int i = 1 ; i <= x ; i++)	res[i][i] = 1;
		//if(k == 0)	return res;
		//Matrix tmp = (*this);
		//while(k){
		//	if(k & 1)	res = res * tmp;
		//	tmp = tmp * (*this);
		//	k >>= 1;
		//}
		//return res;
		if(k == 1)	return (*this);
		Matrix tmp = (*this).pow(k >> 1);
		if(k & 1) return tmp * tmp * (*this);
		return tmp * tmp;
	}
};
int n, m, t;
vector<int>G[1919];
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	Matrix m1(1, n);
	for(int i = 1 ; i <= n ; i++){
		cin >> m1[1][i];
	}
	Matrix m2(n, n);
	for(int i = 1 ; i <= m ; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for(int i = 1 ; i <= n ; i++){
		double gl = (double)1.0 / G[i].size();
		for(auto v:G[i]){
			m2.a[i][v] = gl;
		}
	}
	Matrix res = m1 * m2.pow(t);
	for(int i = 1 ; i <= n ; i++)	cout << fixed << setprecision(10) << res[1][i] << ' ';
	cout << endl;
	return 0;
}
