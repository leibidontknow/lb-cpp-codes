#include<bits/stdc++.h>
using namespace std;
#define int long long
int tree[1919810],n,m;
int a[1919810],tag[1919810];
void pushup(int idx){
    
}
void build(int idx,int l,int r){
    if(l==r){
        tree[idx]=a[l];
        return;
    }
    int mid=l+r>>1;
    build()
}