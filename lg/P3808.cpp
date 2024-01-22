#include<bits/stdc++.h> 
using namespace std;
namespace ACautomanic{
	class acautomanic{
		public:
			struct DictionaryTree{
				int son[26];
				int fail;
				int end;
				DictionaryTree(){
					memset(son, 0, sizeof(son));
					fail = end = 0;
				}
			}t[2000000];
		
		private:
			int change(char ch){
				return ch - 'a';
			}
			int tot;

		public:
			acautomanic(){
				tot = 0;
			}
			void insert(char *str){
				int now = 0;
				for(int i = 0 ; str[i] ; i++){
					int ch = change(str[i]);
					if(!t[now].son[ch])	
						t[now].son[ch] = ++tot; 
					now = t[now].son[ch];
				}
				t[now].end++;
			}
			void init(){
				queue<int> q;
				for(int i = 0 ; i < 26 ; i++){
					if(t[0].son[i])
						q.push(t[0].son[i]);
				}
				while(!q.empty()){
					int now = q.front();
					q.pop();
					for(int i = 0 ; i < 26 ; i++){
						if(t[now].son[i]){
							t[t[now].son[i]].fail = t[t[now].fail].son[i];
							q.push(t[now].son[i]);
						}
						else{
							t[now].son[i] = t[t[now].fail].son[i];
						}
					}
				}
			}
			int query(char *str){
				int now = 0;
				int ans = 0;
				for(int i = 0 ; str[i] ; i++){
					int ch = change(str[i]);
					now = t[now].son[ch];
					int tmp = now;
					while(tmp && t[tmp].end != -1){
						ans += t[tmp].end;
						t[tmp].end = -1;
						tmp = t[tmp].fail;
					}
				}
				return ans;
			}
	};
};
using namespace ACautomanic;
int n;
acautomanic ac;
char str[2000000 + 10];
int main(){
	ios::sync_with_stdio(false);
	cin >>n;
	for(int i = 1 ; i <= n ; i++){
		cin >> str;
		ac.insert(str);
	}
	ac.init();
	cin >> str;
	cout << ac.query(str) << endl;
	return 0;
}