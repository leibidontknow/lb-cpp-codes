#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod =1e9+7;
int m,a,c,x,n,g;
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
    void init(int **b){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                a[i][j]=b[i][j];
            }
        }
    }
};
signed main(){
    cin>>m>>a>>c>>x>>n>>g;
    mod=m;
    if(n<=1){
        cout<<x%g<<endl;
        return 0;
    }
    Matrix m1(1,2);
    m1[1][1]=x;
    m1[1][2]=c;
    Matrix m2(2,2);
    m2[1][1]=a;
    m2[1][2]=0;
    m2[2][1]=1;
    m2[2][2]=1;
    Matrix res=m1*(m2.pow(n));
    cout<<res[1][1]%g<<endl;
    return 0;
}
