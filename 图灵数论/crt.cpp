#include<bits/stdc++.h>
using namespace std;
void ext_gcd(long long a,long long b,long long &d,long long &x,long long &y){
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        ext_gcd(b,a%b,d,y,x);
        y -= a / b * x;
    }
}
int n;
int M;
int m[1919810];
int a[1919810];
int ans;
int main(){
    cin>>n;
    M=1;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
        M*=m[i];
    }
    for(int i=1;i<=n;i++){
        long long d,x,y,t=M/m[i];
        ext_gcd(t,m[i],d,x,y);
        x=t*x%M;
        ans=(ans+x*a[i])%M;
    }
    cout<<(ans+M)%M<<endl;
    return 0;

}
