#include<bits/stdc++.h>
using namespace std;
int n,m;
int head[1919810],dis[1919810],cnt,num[1919810];
int inque[1919810];
int tot=0;
deque<int>q;
struct edge{
    int v,w,nxt;
    edge(){}
    edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}e[1919810];
void add(int u,int v,int w){
    e[++cnt]=edge(v,w,head[u]);
    head[u]=cnt;
}
int spfa(){
    q.push_back(0);
    memset(dis,0x3f,sizeof(dis));
    dis[0]=0;
    inque[0]=1;
    num[0]++;
    while(!q.empty()){
        tot++;
        int u=q.front();
        q.pop_front();
        inque[u]=false;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            int w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inque[v]){
                    inque[v]=1;
                    if(q.size()&&dis[v]>dis[q.front()]){
                        q.push_back(v);
                    }
                    else q.push_front(v);
                    num[v]++;
                    if(num[v]>n+1||tot>1919810)  return -1;
                }
            }
        }
    }
    return dis[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a-1,b,1);
        add(b,a-1,-1);
    }
    for(int i=1;i<=n;i++)   add(i-1,i,1),add(i,i-1,0);
    cout<<spfa()<<endl;
    return 0;
}