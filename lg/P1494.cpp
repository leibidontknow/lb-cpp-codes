#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'
namespace FASTIO{
	class fastI{
		public:
		fastI operator>>(int &x){
			x = 0;
			int f = 1;
			char ch = getchar();
			while(!isdigit(ch))	f = (ch == '-' ? -1 : 1), ch = getchar();
			while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
			return *this; 
		} 
	}fin;
	class fastO{
		public:
		fastO operator<<(int x){
			if(x < 0)	putchar('-'), x = -x;
			if(x > 9)	(*this) << x / 10;
			putchar(x % 10 + '0');
			return (*this);
		}
		fastO operator<<(char ch){
			putchar(ch);
			return (*this);
		}
		fastO operator<<(const char *s){
			printf("%s", s);
			return (*this);
		}
		fastO operator<<(string s){
			(*this) << s.c_str();
			return (*this);
		}
	}fout;
}; 
using namespace FASTIO;
#define cin fin 
#define cout fout
int gcd(int a, int b){
	if(a < b)	swap(a, b);
	if(b == 0)	return a;
	return gcd(b, a % b);
}
const int N = 5e4 + 10;
int a[N], cnt[N], ans1[N], ans2[N];
int siz;
struct query{
	int l, r;
	int id;
}qry[N];
inline bool cmp(const query &a, const query &b){
	if(a.l / siz == b.l / siz)	return a.r < b.r;
	return a.l / siz < b.l / siz;
}
int res = 0; 
void add(int x){
	res += cnt[a[x]];
	cnt[a[x]]++;
}
void del(int x){
	cnt[a[x]]--;
	res -= cnt[a[x]];
}
void yuef(int &a, int &b){
	if(a == 0){
		b = 1;
		a = 0;
		return;
	}
	int tmp = gcd(a, b);
	a /= tmp;
	b /= tmp;
}
int n, m;
signed main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= m ; i++){
		cin >> qry[i].l >> qry[i].r;
		qry[i].id = i;
	}
	siz = 500;
	sort(qry + 1, qry + 1 + m, cmp);
	int l = qry[1].l;
	int r = qry[1].r;
	for(int i = l ; i <= r ; i++){
		add(i);
	}
	int id = qry[1].id;
	ans1[id] = res;
	ans2[id] = (r - l + 1) * (r - l) / 2;
	yuef(ans1[id], ans2[id]);
	for(int i = 1 ; i <= m ; i++){
		id = qry[i].id; 
		if(qry[i].l == qry[i].r){
			ans1[id] = 0;
			ans2[id] = 1;
			continue;
		}
		while(l > qry[i].l)
			add(--l);
		while(r < qry[i].r)
			add(++r);
		while(l < qry[i].l)
			del(l++);
		while(r > qry[i].r)
			del(r--);
		ans1[id] = res;
		ans2[id] = (r - l + 1) * (r - l) / 2;
		yuef(ans1[id], ans2[id]);
	}
	for(int i = 1 ; i <= m ; i++){
		cout << ans1[i] << '/' << ans2[i] << '\n';
	}
	return 0;
}