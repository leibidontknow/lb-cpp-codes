#include<bits/stdc++.h>
using namespace std;
int n,m;
queue<int>q;
int dis[1919810],inque[1919810],num[1919810];
struct edge{
    int v,w;
    edge(){}
    edge(int v,int w):v(v),w(w){}
};
vector<edge>G[1919810];
bool spfa(){
    memset(dis,0xcf,sizeof(dis));
    memset(inque,0,sizeof(inque));
    memset(num,0,sizeof(num));
    q.push(n+1);
    inque[n+1]=1;
    dis[n+1]=0;
    num[n+1]++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inque[u]=false;
        for(edge e:G[u]){
            int v=e.v,w=e.w;
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inque[v]){
                    q.push(v);
                    num[v]++;
                    inque[v]=1;
                    if(num[v]>n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int T;
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a-1].push_back(edge(b,c));
        G[b].push_back(edge(a-1,-c));
    }
    for(int i=0;i<=n;i++)   G[n+1].push_back(edge(i,0));
    if(spfa()){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
    for(int i=0;i<=n+1;i++)   G[i].clear();
    }
    return 0;
}
