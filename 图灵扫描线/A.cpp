#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MAXN=50000+10;
int n,ans;
struct st{
    bool operator()(const int &x,const int &y){return x>y;}
};
multiset<int,st>ms;
struct scanline{
    int pos;
    int h;
    bool left;
}a[MAXN*2+10];
bool cmp(scanline a,scanline b){
    return a.pos<b.pos;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,r,h;
        cin>>l>>r>>h;
        a[2*i-1]={l,h,true};
        a[2*i]={r,h,false};
    }
    sort(a+1,a+1+2*n,cmp);
    ms.insert(0);
    for(int i=1;i<=n*2;i++){
        ans+=(*ms.begin())*(a[i].pos-a[i-1].pos);
        if(a[i].left)   ms.insert(a[i].h);
        else ms.erase(ms.find(a[i].h));
    }
    cout<<ans<<endl;
    return 0;
}