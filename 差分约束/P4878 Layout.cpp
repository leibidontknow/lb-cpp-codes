#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m1,m2;
queue<int>q;
int dis[1919810],inque[1919810],num[1919810];
struct edge{
    int v,w;
    edge(){}
    edge(int v,int w):v(v),w(w){}
};
vector<edge>G[1919810];
bool spfa(int s){
    q.push(s);
    inque[s]=1;
    memset(num,0,sizeof(num));
    memset(inque,0,sizeof(inque));
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inque[u]=false;
        for(edge e:G[u]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                num[v]++;
                if(!inque[v]){
                    q.push(v);
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
int main(){
    memset(dis,0x3f,sizeof(dis));
    ios::sync_with_stdio(false);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(edge(v,w));
    }
    for(int i=1;i<=m2;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[v].push_back(edge(u,-w));
    }
    for(int i=2;i<=n;i++)   G[i-1].push_back(edge(i,inf));
    spfa(1);
    if(dis[n]>=inf){
        cout<<-2<<endl;
        return 0;
    }
    int tmp=dis[n];
    spfa(3);
    if(tmp<dis[n]){
        cout<<-1<<endl;
    }
    else{
        cout<<dis[n]<<endl;
    }
    return 0;
}
