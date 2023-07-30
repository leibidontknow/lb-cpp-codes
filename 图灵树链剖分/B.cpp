#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>G[1919810];
int dep[1919810],fa[1919810],son[1919810],top[1919810],dfn[1919810];
int t,sz[1919810],_cnt,a[1919810],nfd[1919810];
void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    son[u]=-1;
    sz[u]=1;
    for(int v:G[u]){
        if(v!=f){
            dfs1(v,u);
            sz[u]+=sz[v];
            if(son[u]==-1||sz[v]>sz[son[u]]){
                son[u]=v;
            }
        }
    }
}
void dfs2(int u,int p){
    dfn[u]=++_cnt;
    nfd[dfn[u]]=u;
    if(son[u]==-1)  return;
    top[son[u]]=top[u];
    dfs2(son[u],u);
    for(int v:G[u]){
        if(v!=son[u]&&v!=p){
            top[v]=v;
            dfs2(v,u);
        }
    }
}


int tree[5000000+10],tag[5000000+10];
int n,m;
void build(int idx,int l,int r){
	if(l==r){
		tree[idx]=a[nfd[l]];
		return;
	}
	int mid=l+r>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	tree[idx]=tree[idx<<1]+tree[idx<<1|1];
}
int from,to,x;
void apply(int idx,int x,int l,int r){
	tag[idx]+=x;
	tree[idx]+=x*(r-l+1);
}
void update(int idx,int l,int r){
	if(from<=l&&r<=to){
		tree[idx]+=(r-l+1)*x;
		tag[idx]+=x;
		return ;
	}
	int mid=l+r>>1;
	apply(idx<<1,tag[idx],l,mid);
	apply(idx<<1|1,tag[idx],mid+1,r);
	tag[idx]=0;
	if(from<=mid)	update(idx<<1,l,mid);
	if(to>mid) update(idx<<1|1,mid+1,r);
	tree[idx]=tree[idx<<1]+tree[idx<<1|1];
}
int query(int idx,int l,int r){
	if(from<=l&&r<=to){
		return tree[idx];
	}
	int mid=l+r>>1;
	apply(idx<<1,tag[idx],l,mid);
	apply(idx<<1|1,tag[idx],mid+1,r);
	tag[idx]=0;
	int sum=0;
	if(from<=mid)	sum+=query(idx<<1,l,mid);
	if(to>mid)	sum+=query(idx<<1|1,mid+1,r);
	tree[idx]=tree[idx<<1]+tree[idx<<1|1];
	return sum;
}

signed main(){
	ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    top[1]=1;
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    //for(int i=1;i<=n;i++)   cout<<dfn[i]<<' ';
    //cout<<endl;
    for(int i=1;i<=m;i++){
        int opt,aa,bb;
        cin>>opt>>aa;
        if(opt==1){
            cin>>bb;
            from=dfn[aa];
            to=dfn[aa];
            x=bb;
            update(1,1,n);
        }
        else if(opt==2){
            cin>>bb;
            from=dfn[aa];
            to=dfn[aa]+sz[aa]-1;
            x=bb;
            update(1,1,n);
        }
        else{
            int sum=0;
            while(top[aa]!=1){
                from=dfn[top[aa]];
                to=dfn[aa];
                sum+=query(1,1,n);
                aa=fa[top[aa]];
                //cout<<from<<' '<<to<<endl;
            }
            from=1;
            to=dfn[aa];
            sum+=query(1,1,n);
            cout<<sum<<endl;
        }
    }
	return 0;
}











