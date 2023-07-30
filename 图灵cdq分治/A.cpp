#include<bits/stdc++.h>
using namespace std;
#define lowbit(x)   x&(-x)
int ans[5919810],tmp[5919810],n,k,m,btree[5919810];
struct Point{
    int x;
    int y;
    int z;
    int c;
    int f;
}p[5919810];
bool cmp(const Point& a,const Point &b){
    if(a.x!=b.x)    return a.x<b.x;
    if(a.y!=b.y)    return a.y<b.y;
    return a.z<b.z;
}
bool cmpi(int i,int j){
    if(p[i].y!=p[j].y)  return p[i].y<p[j].y;
    if(p[i].z!=p[j].z)  return p[i].z<p[j].z;
    return i<j;
}
void update(int x,int val){
    for(;x<=k;x+=lowbit(x)) btree[x]+=val;
}
int query(int x){
    int s=0;
    for(;x;x-=lowbit(x))    s+=btree[x];
    return s;
}
void solve(int l,int r){
    if(l>=r)    return;
    int mid=l+r>>1;
    solve(l,mid);
    solve(mid+1,r);
    for(int i=l;i<=r;i++)   tmp[i]=i;
    sort(tmp+l,tmp+r+1,cmpi);
    for(int i=l;i<=r;i++){
        if(tmp[i]>mid)  p[tmp[i]].f+=query(p[tmp[i]].z);
        else update(p[tmp[i]].z,p[tmp[i]].c);
    }
    for(int i=l;i<=mid;i++) update(p[i].z,-p[i].c);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)   cin>>p[i].x>>p[i].y>>p[i].z;
    sort(p,p+n,cmp);
    p[0].c=1;
    m=1;
    for(int i=1;i<n;i++){
        if(p[i].x==p[m-1].x&&p[i].y==p[m-1].y&&p[i].z==p[m-1].z)    p[m-1].c++;
        else{
            p[m]=p[i];
            p[m++].c=1;
        }
    }
    solve(0,m-1);
    for(int i=0;i<m;i++)    ans[p[i].f+p[i].c-1]+=p[i].c;
    for(int i=0;i<n;i++)    cout<<ans[i]<<endl;
    return 0;
}