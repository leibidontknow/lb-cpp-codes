#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n,m,k;
vector<int>G[191];
// int dp[100000+10];
int dfs(int nw,int nxt,int lesson){
    cout<<nw<<endl;
    int add=0;
    if(lesson==k){
        lesson=0;
        add=1;
        nw|=nxt;
        nxt=0;
    }
    if(nw==(1<<n)-1)    return add;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if((nw>>(i-1))&1)   continue;
        if((nxt>>(i-1))&1)  continue;
        bool flag=true;
        for(int v:G[i]){
            if(nw&(1<<(v-1))){
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==false) continue;
        ans=min(ans,dfs(nw,nxt|(1<<(i-1)),lesson+1));
    }
    ans+=add;
    if(lesson!=0){
        lesson=0;
        
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[v].push_back(u);
    }
    int ans=dfs(0,0,1);
    for(int i=1;i<=k;i++){
        ans=min(ans,dfs(0,0,i));
    }
    cout<<ans+1<<endl;
    return 0;
}