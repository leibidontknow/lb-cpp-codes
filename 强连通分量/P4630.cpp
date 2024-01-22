#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int n,m;
int to[N],head[N],nxt[N];
void add(int u,int v){
    static int cnt = 0;
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
int toT[N],headT[N],nxtT[N];
void addT(int u,int v){
    static int cntT = 0;
    toT[++cntT] = v;
    nxtT[cntT] = headT[u];
    headT[u] = cntT;
}
vector<int>Tree[N];
int dfn[N],low[N],cnt,sz[N],fsz[N],num,st[N],top,yd;
int ans;
void tarjan(int u){
    low[u] = dfn[u] = ++cnt;
    st[++top] = u;
    yd++;
    for(int i = head[u];i;i = nxt[i]){
        int v = to[i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
            if(low[v] >= dfn[u]){
                fsz[++num]=0;
                while(1){
                    int tmp = st[top--];
                    addT(num,tmp);
                    addT(tmp,num);
                    fsz[num]++;
                    if(tmp == v)  break;
                }
                addT(u,num);
                addT(num,u);
                fsz[num]++;
            }
        }
        else low[u] = min(low[u],dfn[v]);
    }
}
void dfs(int u,int fa){
    sz[u] = (u <= n);
    for(int i = headT[u];i;i = nxtT[i]){
        int v = toT[i];
        if(v != fa){
            dfs(v,u);
            ans += 2ll * fsz[u] * sz[u] * sz[v];
            sz[u] += sz[v];
        }
    }
    ans += 2ll * fsz[u] * sz[u] * (yd - sz[u]);
}
signed main(){
    memset(fsz,-1,sizeof(fsz));
    cin >> n >> m;
    num = n;
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    for(int i = 1;i <= n;i++){
        if(!dfn[i]){
            yd = 0;
            tarjan(i);
            dfs(i,0);
        }
    }
    cout << ans << endl;
    return 0;
}
