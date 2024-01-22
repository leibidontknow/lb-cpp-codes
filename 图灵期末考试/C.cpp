#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y xfmsm_y
int n;
int ans=LLONG_MIN;
int mxx1=INT_MAX,mxy1=INT_MAX,mxx2=INT32_MIN,mxy2=INT32_MIN;
struct block{
    int x1,y1,x2,y2,w;
    block(){}
    block(int x1,int y1,int x2,int y2,int w):x1(x1),y1(y1),x2(x2),y2(y2),w(w){}
};
vector<block>vec;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        vec.push_back(block(a,b,c,d,e));
        mxx1=min(a,mxx1);
        mxy1=min(b,mxy1);
        mxx2=max(c,mxx2);
        mxy2=max(d,mxy2);
    }
    for(int x=mxx1;x<=mxx2;x++){
        for(int y=mxy1;y<=mxy2;y++){
            int tmp=0;
            for(auto v:vec){
                if(x>v.x1&&x<v.x2&&y>v.y1&&y<v.y2)  tmp+=v.w;
            }
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}