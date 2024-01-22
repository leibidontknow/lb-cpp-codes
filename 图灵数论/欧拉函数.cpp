#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
#define int long long
const int maxn=3.2e7+10;
bool vis[maxn];
int minp[maxn],phi[maxn];
long long ans=0;
signed main(){
    vis[1]=1;
    for(int i=2;i<=maxn;i++){
        if(!vis[i]) primes.push_back(i),phi[i] = i-1;
        for(int p:primes){
            if(i*p*1ll>maxn)    break;
            vis[i*p]=1;
            if(i%p==0)  {phi[i*p]=phi[i]*p;break;}
            else phi[i*p]=phi[i]*(p-1);
        }
    }
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        ans=1;
        for(int p:primes){
            if(n<=maxn) break;
            if(1ll*p*p>n){
                ans=ans*(n-1);
                n=1;
                break;
            }
            if(n%p==0){
                ans *= p-1;
                n /= p;
                while(n%p==0){
                    ans*=p;
                    n/=p;
                }
            }
        }
        if(n>1) ans*=phi[n];
        cout<<ans<<endl;
    }
    return 0;
}