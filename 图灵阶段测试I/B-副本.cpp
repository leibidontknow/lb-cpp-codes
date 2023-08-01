#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>G[1919810];
int du[1919810];
int ans=0;
typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> >q;
int calc=0;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        du[v]++;
    }
    for(int i=1;i<=n;i++){
        if(du[i]==0)    q.push(make_pair(0,i));
    }
    while(1){
        vector<int>passd;
        ans++;
        for(int i=1;i<=k;i++){
            if(q.size()){
                int tmp=q.top().second;
                q.pop();
                calc++;
                for(int v:G[tmp]){
                    passd.push_back(v);
                }
            }
        }
        for(int v:passd){
            du[v]--;
            if(du[v]==0)    q.push(make_pair(ans,v));
        }
        if(calc==n)   break;
    }
    cout<<ans<<endl;
    return 0;
}