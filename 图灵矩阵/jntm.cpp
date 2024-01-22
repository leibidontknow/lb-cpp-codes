#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod =1e9+7;
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
int n,k,b,s,v,t;
signed main(){
    cin>>n>>k>>b;
    int Q;
    cin>>Q;
    while(Q--){
        cin>>s>>v>>t;
        mod=n;
        Matrix m1(1,3);
        m1[1][1]=s;
        m1[1][2]=v;
        m1[1][3]=b;
        Matrix m2(3,3);
        m2[1][1]=1;
        m2[1][2]=k;
        m2[1][3]=0;
        m2[2][1]=1;
        m2[2][2]=1+k;
        m2[2][3]=0;
        m2[3][1]=0;
        m2[3][2]=1;
        m2[3][3]=1;
        Matrix res=m1*(m2.pow(t));
        cout<<res[1][1]<<endl;

    }
   
    return 0;
}
