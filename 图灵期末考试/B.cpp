#include<bits/stdc++.h>
using namespace std;
bool isprime(int num) {
  if(num<=3) {
    return num>1;
  }
  if(num%6!=1&&num%6!=5) {
    return false;
  }
  for(int i=5; i<=sqrt(num); i+=6) {
    if(num%i==0||num%(i+2)==0) {
      return false;
    }
  }
  return true;
}
struct edge{
	int to,nxt;
}e[2000000+10];
int a[1919810];
int n,m,s;
int dp[500000+10][25],head[2000000+10],dep[500000+10],sum=0;
void getdp(int now,int father){
	dp[now][0]=father;
	dep[now]=dep[father]+1;
	for(int i=1;(1<<i)<=dep[now];i++){
		dp[now][i]=dp[dp[now][i-1]][i-1];
	}
	for(int i=head[now];i;i=e[i].nxt){
		if(e[i].to!=father)	getdp(e[i].to,now);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b]){
		swap(a,b);
	}
	for(int i=21;i>=0;i--){
		if(dep[a]-(1<<i)>=dep[b])	a=dp[a][i];
	}
	if(a==b){
		return b;
	}
	for(int i=21;i>=0;i--){
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i],b=dp[b][i];
		}
	}
	return dp[b][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    s=1;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[++sum].to=y;
		e[sum].nxt=head[x];
		head[x]=sum;
		e[++sum].to=x;
		e[sum].nxt=head[y];
		head[y]=sum;
	}
    getdp(s,0);
    cin>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int lc=lca(x,y);
        unordered_map<int,int>mp;
        while(x!=lc){
            mp[a[x]]++;
            x=dp[x][0];
        }
        while(y!=lc){
            mp[a[y]]++;
            y=dp[y][0];
        }
        mp[a[lc]]++;
        int sum=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(isprime((*it).second))   sum^=(*it).first;
        }
        cout<<sum<<endl;
    }
    return 0;
}