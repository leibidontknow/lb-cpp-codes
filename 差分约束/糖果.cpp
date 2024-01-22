#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
stack<int>q;
int dis[1919810],inque[1919810],num[1919810];
struct E{
    int v,w,nxt;
    E(){}
    E(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}e[1919810];
int cnt;
int head[1919810];
void add(int u,int v,int w){
    e[++cnt]=E(v,w,head[u]);
    head[u]=cnt;
}
bool spfa(){
    q.push(0);
    inque[0]=1;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        inque[u]=false;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            int w=e[i].w;
            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inque[v]){
                    q.push(v);
                    inque[v]=1;
                    num[v]++;
                    if(num[v]>n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int x,a,b;
        cin>>x>>a>>b;
        if(x==1){
            add(a,b,0);
            add(b,a,0);
        }
        if(x==2)    add(a,b,1);
        if(x==3)    add(b,a,0);
        if(x==4)    add(b,a,1);
        if(x==5)    add(a,b,0);
    }
    for(int i=1;i<=n;i++){
        add(0,i,1);
    }
    if(spfa()){
        cout<<"-1"<<endl;
    }
    else{
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=dis[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}