#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
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
};
int main(){
    int r,c;
    cin>>r>>c;
    Matrix m1(r,c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>m1[i][j];
        }
    }
    cin>>r>>c;
    Matrix m2(r,c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>m2[i][j];
        }
    }
    (m1*m2).print();
    return 0;
}
