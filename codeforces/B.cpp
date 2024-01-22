#include<bits/stdc++.h>
using namespace std;
int n,T;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int ll=0,rr=0;
        int mxl=0,mxr=0;
        cin>>n;
        cin>>s;
        for(int i=1;i<n;i++){
            if(s[i-1]=='<'&&s[i]=='<'){
                mxr=0;
                mxl++;
                ll=max(ll,mxl);
            }
            else{
                mxl=0;
            }
            if(s[i-1]=='>'&&s[i]=='>'){
                mxl=0;
                mxr++;
                rr=max(rr,mxr);
            }
            else{
                mxr=0;
            }
        }
        cout<<max(ll,rr)+2<<endl;
    }
    return 0;
}