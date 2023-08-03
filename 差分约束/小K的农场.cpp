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
    q.push(0);
    inque[0]=1;
    memset(dis,0x3f,sizeof(dis));
    dis[0]=0;
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
                }
                if(num[v]>n+1){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,a,b,c;
        cin>>x;
        if(x==3){
            cin>>a>>b;
            G[a].push_back(edge(b,0));
            G[b].push_back(edge(a,0));
        }
        if(x==1){
            cin>>a>>b>>c;
            G[a].push_back(edge(b,-c));
        }
        if(x==2){
            cin>>a>>b>>c;
            G[b].push_back(edge(a,c));
        }
    }
    for(int i=1;i<=n;i++)   G[0].push_back(edge(i,0));
    if(spfa()){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
