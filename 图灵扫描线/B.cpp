#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
struct scanline{
    int x,y1,y2;
    bool left;
    bool operator<(const scanline &a)const{
        return x<a.x;
    }
}e[N*2];
struct node{
    int cnt;
    int len;
    int tot;
}t[8*N];
void build(int idx,int l,int r){
    t[idx].tot=r-l+1;
    if(l>=r)    return;
    int mid=l+r>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
}
void pushup(int idx){
    if(t[idx].cnt>0)    t[idx].len=t[idx].tot;
    else t[idx].len=t[idx<<1].len+t[idx<<1|1].len;
}
void update(int idx,int l,int r,int x,int y,int val){
    //if(idx!=0)  cout<<x<<endl;
    if(x<=l&&y>=r){
        t[idx].cnt+=val;
        pushup(idx);
        return;
    }
    int mid=l+r>>1;
    if(y<=mid)  update(idx<<1,l,mid,x,y,val);
    else if(x>mid)  update(idx<<1|1,mid+1,r,x,y,val);
    else{
        update(idx<<1,l,mid,x,mid,val);
        update(idx<<1|1,mid+1,r,mid+1,y,val);
    }
    pushup(idx);
}
long long ans;
int main(){
    int n,m=0,cnt,x1,x2,y1,y2;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        if(y1==y2)  continue;
        e[cnt++]={x1,y1,y2,true};
        e[cnt++]={x2,y1,y2,false};
        m=max(m,y2);
    }
    build(1,0,m-1);
    sort(e,e+cnt);
    update(1,0,m-1,e[0].y1,e[0].y2-1,1);
    for(int i=1;i<cnt;i++){
        ans+=1LL*(e[i].x-e[i-1].x)*t[1].len;
        if(e[i].left)   update(1,0,m-1,e[i].y1,e[i].y2-1,1);
        else update(1,0,m-1,e[i].y1,e[i].y2-1,-1);
    }
    cout<<ans<<endl;
    return 0;
}