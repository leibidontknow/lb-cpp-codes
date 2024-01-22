/*************************************************************************
	> File Name: P1306.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e8;
int n, m;
int gcd(int a, int b){
	if(!a || !b)	return a + b;
	if(b > a)	swap(a, b);
	return gcd(b, a % b);
}
struct Matrix{
    int x,y;
    vector<vector<int> >a;
    Matrix(int r,int c):x(r),y(c){
        a=vector<vector<int> >(r+1,vector<int>(c+1));
    }
    vector<int>& operator[](int i){return a[i];}
    const vector<int>& operator[](int i)const{return a[i];}
    Matrix operator*(const Matrix& b)const{
        Matrix res(x,b.y);
        for(int i=1;i<=x;i++){
            for(int j=1;j<=b.y;j++){
                for(int k=1;k<=y;k++){
                    res[i][j]=(res[i][j]+(long long)a[i][k]*b[k][j])%mod;
                    res[i][j]+=mod;
                    res[i][j]%=mod;
                }
            }
        }
        return res;
    }
    void init(){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cin>>a[i][j];
            }
        }
    }
    void print(string s=" ",string ss="\n"){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                cout<<a[i][j]<<s;
            }
            cout<<ss;
        }
    }
    Matrix operator*=(const Matrix&b){
        return (*this)=(*this)*b;
    }
    Matrix operator*(int b){
        Matrix res(x,y);
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                res[i][j]=a[i][j]*b%mod;
                res[i][j]=(res[i][j]+mod)%mod;
            }
        }
        return res;
    }
    Matrix operator*=(int b){
        return (*this)=(*this)*b;
    }
    Matrix pow(int k){
		Matrix tmp(x, y);
		for(int i = 1 ; i <= x ; i++)	tmp[i][i] = 1;
		if(k == 0) return tmp;
        if(k==1)    return (*this);
        tmp=(*this).pow(k>>1);
        if(k&1) return tmp*tmp*(*this);
        return tmp*tmp;
    }
};
signed main(){
    cin >> n >> m;
    Matrix m1(1,2);
    m1[1][1]=1;
    m1[1][2]=1;
    Matrix m2(2,2);
    m2[1][1]=1;
    m2[1][2]=1;
    m2[2][1]=1;
    if(__gcd(n, m) <= 1){
        cout << 1 << endl;
        return 0;
    }
    Matrix res=m1*(m2.pow(gcd(n, m)));
    cout<<res[1][1] % mod<<endl;
    return 0;
}
