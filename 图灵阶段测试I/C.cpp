#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r,x,y;
int x1,x2;
int solve(int n){
    int dp[300][2][2];
    int d[300];
    int len=0;
    memset(dp,0,sizeof(dp));
    memset(d,0,sizeof(d));
    do{
        d[len++]=n%10;
        n/=10;
    }while(n);
    dp[len][0][1]=1;
    for(int i=len;i>0;i--){
        for(int j=0;j<=1;j++){
            for(int t=0;t<=1;t++)
            for(int c=0;c<=9;c++){
                if(j==1&&c>d[i-1])    continue;
                int nt=0,nj=0;
                if(c==y)    continue;
                if(t==0){
                    if(c==x1){
                        nt=1;
                    }
                    if(j==1&&c==d[i-1]){
                        nj=1;
                    }
                    dp[i-1][nt][nj]+=dp[i][t][j];
                }
                else{
                    if(c==x2)   continue;
                    if(c==x1){
                        nt=1;
                    }
                    if(j==1&&c==d[i-1]) nj=1;
                    dp[i-1][nt][nj]+=dp[i][t][j];
                }
    //             int nt,nj;
    //             if(c==x1) nt=1;
    //             if(nt==0){
    //                 dp[i-1][0]
    //             }
    //             dp[i-1][nt][0]+=dp[i][0];
    //             if(c==d[i-1]){
    //                 dp[i-1][1]+=dp[i][1];
    //             }
    //             else{
    //                 dp[i-1][0]+=dp[i][1];
    //             }
            }
        }
        
    }
    return dp[0][0][1]+dp[0][0][0]+dp[0][1][1]+dp[0][1][0];
}

int solve2(int n){
    int dp[300][2][2][2];
    int d[300];
    int len=0;
    memset(dp,0,sizeof(dp));
    memset(d,0,sizeof(d));
    do{
        d[len++]=n%10;
        n/=10;
    }while(n);
    dp[len][0][1][0]=1;
    for(int i=len;i>0;i--){
        for(int j=0;j<=1;j++){
            for(int t=0;t<=1;t++)
            for(int k=0;k<=1;k++)
            for(int c=0;c<=9;c++){
                int nk=0;
                if(c!=0){
                    nk=1;
                }
                if(j==1&&c>d[i-1])    continue;
                int nt=0,nj=0;
                if(c==y&&!(y==0&&k==0))    continue;
                if(t==0){
                    if(c==x1){
                        nt=1;
                    }
                    if(j==1&&c==d[i-1]){
                        nj=1;
                    }
                    dp[i-1][nt][nj][nk]+=dp[i][t][j][k];
                }
                else{
                    if(c==x2)   continue;
                    if(c==x1){
                        nt=1;
                    }
                    if(j==1&&c==d[i-1]) nj=1;
                    dp[i-1][nt][nj][nk]+=dp[i][t][j][k];
                }
    //             int nt,nj;
    //             if(c==x1) nt=1;
    //             if(nt==0){
    //                 dp[i-1][0]
    //             }
    //             dp[i-1][nt][0]+=dp[i][0];
    //             if(c==d[i-1]){
    //                 dp[i-1][1]+=dp[i][1];
    //             }
    //             else{
    //                 dp[i-1][0]+=dp[i][1];
    //             }
            }
        }
        
    }
    // cout<<len<<endl;
    // for(int i=len;i>=0;i--){
    //     cout<<dp[i][0][1]<<' '<<dp[i][0][0]<<' '<<dp[i][1][1]<<' '<<dp[i][1][0]<<endl;
    // }
    return dp[0][0][1][1]+dp[0][0][0][1]+dp[0][1][1][1]+dp[0][1][0][1];
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>l>>r>>y>>x;
    x1=x/10;
    x2=x%10;
    if(y==0)    cout<<solve2(r)-solve2(l-1)<<endl;
    else cout<<solve(r)-solve(l-1)<<endl;
    return 0;
}