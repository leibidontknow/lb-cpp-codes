#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod;
int n,k;
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
        if(k==1)    return (*this);
        Matrix tmp=(*this).pow(k>>1);
        if(k&1) return tmp*tmp*(*this);
        return tmp*tmp;
    }
};
Matrix m1(1,2);
Matrix m2(2,2);
void init(){
    m1[1][1]=1;
    m1[1][2]=1;
    m2[1][1]=1;
    m2[1][2]=1;
    m2[2][1]=1;
}
int fibo(int n){
    if(n<=2){
        return 1;
    }
	Matrix res = m1 * (m2.pow(n - 2));
	return res[1][1];
}
int fastpow(int x, int y){
	int tmp = 1;
	while(y > 0){
		if(y & 1)	tmp = (tmp * x) % mod;
		x = (x * x) % mod;
		y >>= 1;	
	}
	return tmp;
}
void solve(){
	int x, y, a, m;
	cin >> x >> y >> a >> m;
	mod = INT_MAX;
	int u = fastpow(a, fibo(x)) - 1;
	int v = fastpow(a, fibo(y)) - 1;
	// cout << fibo(x) << ' ' << fibo(y) << endl;
	cout << (u * v % mod) / __gcd(u, v) / __gcd(u, v) % m << endl;
}
signed main(){
	int T;
	init();
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)	solve();
    return 0;
}