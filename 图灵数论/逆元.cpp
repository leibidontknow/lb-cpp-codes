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
int T;
long long a,m,d,x,y;
int main(){
    cin>>T;
    while(T--){
        cin>>a>>m;
        ext_gcd(a,m,d,x,y);
        if(d!=1){
            cout<<-1<<endl;
        }
        else{
            cout<<(x+m)%m<<endl;
        }
    }
    return 0;

}
