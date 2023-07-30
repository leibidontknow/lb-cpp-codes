#include<bits/stdc++.h>
using namespace std;
#define MAXN 191981
#define MAXM 1919810
int res;
int a[MAXN],ans[MAXN],cntq,cntr,n,m,sz;
int cnt[MAXM];
struct node{
    int l,r,t,id;
}qq[MAXN],qr[MAXN];
bool cmp(const node &a,const node &b){
    return a.l / sz == b.l / sz ? a.r / sz == b.r / sz ? a.t < b.t : a.r < b.r : a.l < b.l;
}
inline void add(int x){
    res+=!cnt[x]++;
}
inline void del(int x){
    res-=!--cnt[x];
}
inline void update(int x,int d){
    if(qq[x].l<=qr[d].l&&qr[d].l<=qq[x].r){
        del(a[qr[d].l]);
        add(qr[d].r);
    }
    swap(a[qr[d].l],qr[d].r);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sz=pow(n,0.666);
    for(int i=1;i<=m;i++){
        int l,r;
        char opt;
        cin>>opt>>l>>r;
        if(opt=='Q'){
            ++cntq;
            qq[cntq]={l,r,cntr,cntq};
        }
        else{
            ++cntr;
            qr[cntr]={l,r,0,0};
        }
    }
    sort(qq+1,qq+1+cntq,cmp);
    int l=1,r=0,t=0;
    for(int i=1;i<=cntq;i++){
        while(l>qq[i].l)    add(a[--l]);
        while(l<qq[i].l)    del(a[l++]);
        while(r>qq[i].r)    del(a[r--]);
        while(r<qq[i].r)    add(a[++r]);
        while(t<qq[i].t)    update(i,++t);
        while(t>qq[i].t)    update(i,t--);
        ans[qq[i].id]=res;
    }
    for(int i=1;i<=cntq;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}