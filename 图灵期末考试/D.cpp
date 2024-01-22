#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int n, m, s, t;
struct Edge {
  int v, r, c, cp;
};
vector<Edge> g[maxn];
int dis[maxn];
bool inq[maxn];
int cur[maxn];
bool vis[maxn];
void add_edge(int u, int v, int c, int w) {
  g[u].push_back(Edge{v, c, w, (int)g[v].size()});
  g[v].push_back(Edge{u, 0, -w, (int)g[u].size() - 1});
}
bool spfa() {
  queue<int> que;
  memset(dis, 0x3f, sizeof(dis));
  memset(inq, false, sizeof(inq));
  dis[s] = 0, inq[s] = true, que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    inq[u] = false;
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i].v, r = g[u][i].r, c = g[u][i].c;
      if (r && dis[u] + c < dis[v]) {
        dis[v] = dis[u] + c;
        if (!inq[v]) inq[v] = true, que.push(v);
      }
    }
  }
  return dis[t] != inf;
}

int aug(int u, int m, int &cost) {
  if (u == t) return m;
  vis[u] = true;
  int flow = 0;
  for (int& i = cur[u]; i < g[u].size(); ++i) {
    int v = g[u][i].v, r = g[u][i].r, c = g[u][i].c, j = g[u][i].cp;
    if (vis[v] || r == 0 || dis[v] != dis[u] + c) continue;
    int d = aug(v, min(m - flow, r), cost);
    g[u][i].r -= d, g[v][j].r += d, flow += d, cost += d * c;
    if (flow == m) break;
  }
  vis[u] = false;
  return flow;
}
int a[maxn],b[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=n+1;i<=2*n;i++)   cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=n+1;j<=2*n;j++){
            int x;
            cin>>x;
            if(x!=-1){
                add_edge(i,j,min(a[i],b[j]),x);
            }
        }
    }
    s=2*n+1,t=2*n+2;
    for(int i=1;i<=n;i++){
        add_edge(s,i,a[i],0);
    }
    for(int i=n+1;i<=2*n;i++)   add_edge(i,t,b[i],0);
 /* cin >> n >> m; 
  s = 1, t = n;
  while (m--) {
    int u, v, c, w;
    cin >> u >> v >> c >> w;
    add_edge(u, v, c, w);
  }
  */
  int flow = 0, cost = 0;
  while (spfa()) {
    memset(cur, 0, sizeof(cur));
    flow += aug(s, inf, cost);
  }
  cout << flow << " " << cost << endl;

  return 0;
}