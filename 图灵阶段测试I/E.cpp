#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1919810],c[1919810];
vector<int>G[1919];
int sum;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i],sum+=a[i];
    for(int i=1;i<=n;i++)   cin>>c[i];
    cout<<sum<<endl;
    return 0;
}