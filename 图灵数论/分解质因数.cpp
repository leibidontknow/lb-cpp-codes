#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
#define int long long
const int maxn=3.2e7+10;
bool vis[maxn];
int minp[maxn];
signed main(){
    vis[1]=1;
    for(int i=2;i<=maxn;i++){
        if(!vis[i]) primes.push_back(i),minp[i] = i;
        for(int p:primes){
            if(i*p*1ll>maxn)    break;
            vis[i*p]=1;
            minp[i*p] = p;
            if(i%p==0)  break;
        }
    }
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        vector<long long>pm;
        for(int p:primes){
            if(n<=maxn) break;
            if(1ll*p*p>n){
                pm.push_back(n);
                n=1;
                break;
            }
            while(n%p==0){
                pm.push_back(p);
                n/=p;
            }
        }
        while(n>1){
            pm.push_back(minp[n]);
            n/=minp[n];
        }
        int cnt=1;
        for(int i=1;i<pm.size();i++){
            if(pm[i]!=pm[i-1]){
                cout<<pm[i-1] << ' ' << cnt << ' ';
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        cout << pm[pm.size() - 1] << ' ' << cnt << endl;
    }
    return 0;
}