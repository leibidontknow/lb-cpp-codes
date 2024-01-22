#include<bits/stdc++.h>
using namespace std;
int l,r,x;
int dp[30][10];
void init(){
    for(int i=1;i<=9;i++){
        if(i!=x){
            dp[1][i]=1;
        }
    }
    for(int i=2;i<=20;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<10;k++){
                if(j!=x&&k!=x){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
}
int solve(int n){
    int ans=0;
    int d[30];
    int len=0;
    memset(d,0,sizeof(d));
    do{
        d[++len]=n%10;
        n/=10;
    }while(n);
    for(int i=len-1;i>=1;i--){
        for(int j=1;j<=9;j++){
            if(j==x)    continue;
            ans+=dp[i][j];
        }
    }
    for(int i=1;i<d[len];i++){
        ans+=dp[len][i];
    }
    for(int i=len-1;i>=1;i--){
        for(int j=0;j<d[i];j++){
            if(d[i+1]!=x&&j!=x) ans+=dp[i][j];
        }
        if(d[i+1]==x)   break;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>l>>r>>x;
    init();
    cout<<solve(r+1)-solve(l)<<endl;
    return 0;
}