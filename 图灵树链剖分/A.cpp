#include<bits/stdc++.h>
using namespace std;
vector<int>G[1919810];
int dep[1919810],fa[1919810],son[1919810],top[1919810],dfn[1919810];
int n,q,sz[1919810],_cnt;
void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    son[u]=-1;
    sz[u]=1;
    for(int v:G[u]){
        if(v!=f){
            dfs1(v,u);
            sz[u]+=sz[v];
            if(son[u]==-1||sz[v]>sz[son[u]]){
                son[u]=v;
            }
        }
    }
}
void dfs2(int u,int p){
    dfn[u]=++_cnt;
    if(son[u]==-1)  return;
    top[son[u]]=top[u];
    dfs2(son[u],u);
    for(int v:G[u]){
        if(v!=son[u]&&v!=p){
            top[v]=v;
            dfs2(v,u);
        }
    }
}
int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]){
            b=fa[top[b]];
        }
        else{
            a=fa[top[a]];
        }
    }
    return dep[a]<dep[b]?a:b; 
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    top[1]=1;
    dfs1(1,0);
    dfs2(1,0);
    fa[1]=1;
    // for(int i=1;i<=n;i++)   cout<<top[i]<<' ';
    // cout<<endl;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
    return 0;
}