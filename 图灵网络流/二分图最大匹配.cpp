#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
inline void read(int32_t &tar){
    int32_t x=0,f=1;
    int8_t ch=getchar();
    while(ch<'0'||ch>'9')   f=(ch=='-'?-1:1),ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    tar=x*f;
}
template<typename... Args>
inline void read(int32_t &tar,Args& ...args){
    read(tar),read(args...);
}
inline void write(int32_t x){
    if(x<0) putchar('-'),x=-x;
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
inline void write(int8_t x){
    putchar(x);
}
template<typename T,typename... Args>
inline void write(T x,Args... args){
    write(x),write(args...);
}
int32_t n,m,G[500][500],ans,boy[500],vis[500];
bool dfs(int32_t x){
    for(int32_t i=1;i<=m;i++){
        if(G[x][i]&&!vis[i]){
            vis[i]=true;
            if(!boy[i]||dfs(boy[i]))    return boy[i]=x,true;
        }
    }
    return false;
}
int32_t main(){
    read(n,m);
    for(int32_t i=1;i<=n;i++)
        for(int32_t j=1;j<=m;j++)
            read(G[i][j]);
    for(int32_t i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    write(ans,'\n');
    return 0;
}