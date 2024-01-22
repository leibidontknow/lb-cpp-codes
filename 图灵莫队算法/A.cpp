#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int sz=0;
int ans[114514][2];
int cnt[114514];
int res;
int a[114514];
int gcd(int a,int b){
    if(b==0)    return a;
    return gcd(b,a%b);
}
struct node{
    int l,r,id;
}qry[1919810];
const bool cmp(const node &a,const node &b){
    if(a.l/sz!=b.l/sz)  return a.l/sz<b.l/sz;
    return a.r<b.r;
}
void reduce(int &a,int &b){
    if(b==0){
        a=0;
        b=1;
        return;
    }
    int d=gcd(a,b);
    a/=d;
    b/=d;
}
void update(int i,int d){
    res-=cnt[a[i]]*(cnt[a[i]]-1)/2;
    cnt[a[i]]+=d;
    res+=(long long)cnt[a[i]]*(cnt[a[i]]-1)/2;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>qry[i].l>>qry[i].r;
        qry[i].id=i;
    }
    sz=sqrt(n);
    sort(qry+1,qry+1+m,cmp);
    int l=qry[1].l,r=qry[1].r;
    for(int i=l;i<=r;i++)   update(i,1);
    ans[qry[1].id][0]=res;
    ans[qry[1].id][1]=(r-l+1)*(r-l)/2;
    reduce(ans[qry[1].id][0],ans[qry[1].id][1]);
    for(int i=2;i<=m;i++){
        while(l>qry[i].l)   update(--l,1);
        while(l<qry[i].l)   update(l++,-1);
        while(r>qry[i].r)   update(r--,-1);
        while(r<qry[i].r)   update(++r,1);
        ans[qry[i].id][0]=res;
        ans[qry[i].id][1]=(r-l+1)*(r-l)/2;
        reduce(ans[qry[i].id][0],ans[qry[i].id][1]);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i][0]<<'/'<<ans[i][1]<<endl;
    }
    return 0;
}