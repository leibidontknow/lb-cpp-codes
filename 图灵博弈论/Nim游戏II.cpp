#include<bits/stdc++.h>
using namespace std;
int n,a[1919810];
int xorsum;
int dfs(int x){
    if(x==1)    return 1;
    if(x==0)    return 0;
    if(x&1) return (x+1)/2;
    return dfs(x/2-1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xorsum^=dfs(a[i]);
    }
    if(xorsum==0){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
    }
    
    return 0;
}