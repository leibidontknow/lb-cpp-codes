#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>vec[2000000+10];
int dep[2000000+10],sz[2000000+10];
void dfs1(int now){
    for(int v:vec[now]){
        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        sz[i]=1;
    }
    sz[n]=1;
    dfs1(1);
}