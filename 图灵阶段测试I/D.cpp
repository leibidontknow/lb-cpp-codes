#include<bits/stdc++.h>
using namespace std;
int n,xorsum;
int d[7]={0,1,0,1,0,1,2};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){

        int x;
        cin>>x;
        xorsum^=(d[x%7]);
    }
    if(xorsum!=0){
        cout<<"Alice\n";
    }
    else{
        puts("Bob");
    }
    return 0;
}