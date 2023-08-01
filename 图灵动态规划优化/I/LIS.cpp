#include<bits/stdc++.h>
using namespace std;
int n,a[1919810];
int g[1919810];
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i],g[i]=1e9;
    for(int i=1;i<=n;i++){
        int x=lower_bound(g+1,g+ans+1,a[i])-g;
        g[x]=a[i];
        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}