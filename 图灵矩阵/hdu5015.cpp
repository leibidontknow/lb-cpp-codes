#include<bits/stdc++.h>
using namespace std;
#define max(a,b) [](int c,int d){return c>d?c:d;}(a,b)
#define min(a,b) [](int c,int d){return c<d?c:d;}(a,b)
const int mod =1e7+7;
int n,m;
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
        // Matrix tmp=(*this);
        Matrix res(x,y);
        for(int i=1;i<=x;i++)  res[i][i]=1;
        while(k){
            if(k&1) res*=(*this);
            k>>=1;
            (*this)*=(*this);
        }
        return res;
    }
    void init(int **b){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                a[i][j]=b[i][j];
            }
        }
    }
};
signed main(){
    while(cin>>n>>m){
	    Matrix m1(1,m);
	    m1[1][1]=1;
	    Matrix m2(m,m);
	    for(int i=1;i<=m;i++){
	        for(int j=max(1ll,i-1);j<=min(i+1,m);j++){
	            m2[j][i]=1;
	        }
	    }
	    // for(int i=1;i<=m;i++){
	    //     for(int j=1;j<=m;j++){
	    //         cout<<m2[i][j]<<' ';
	    //     }
	    //     cout<<endl;
	    // }
	    Matrix res=m1*(m2.pow(n-1));
		cout<<res[1][m]<<endl;
		return 0;
	}
}
