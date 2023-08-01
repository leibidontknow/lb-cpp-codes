#include<bits/stdc++.h>
using namespace std;
int n,a[1919810];
int xorsum;
int dfs(int x){
    int res=0;
    if(x%2==0){
        res++;
        while(x%2==0){
            x/=2;
        }
    }
    for(int i=3;i*i<=x;i++){
        while(x%i==0){
            res++;
            x/=i;
        }
    }
    if(x>1) res++;
    return res;
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