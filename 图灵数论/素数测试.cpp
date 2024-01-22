#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
bool vis[50000000+10];
int maxn=4e7;
bool isprime(long long n){
    if(n<=maxn) return !vis[n];
    for(int p:primes){
        if(1ll*p*p>n)   break;
        if(n%p==0)  return 0;
    }
    return 1;
}
signed main(){
    vis[1]=1;
    for(int i=2;i<=maxn;i++){
        if(!vis[i]) primes.push_back(i);
        for(int p:primes){
            if(i*p*1ll>maxn)    break;
            vis[i*p]=1;
            if(i%p==0)  break;
        }
    }
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(!isprime(x)){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}