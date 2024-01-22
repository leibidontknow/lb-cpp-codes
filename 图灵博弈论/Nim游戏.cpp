#include<bits/stdc++.h>
using namespace std;
int n,a[1919810];
int xorsum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xorsum^=a[i];
    }
    if(xorsum==0){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
    }
    return 0;
}