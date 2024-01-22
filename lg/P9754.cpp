#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct Type{
	int cnt;
	int pos[110];
	string sontype[110];
	string sonname[110];
	int align, size;
	Type(){
		cnt = align = size = 0;
		memset(pos, 0, sizeof(pos));
	}
};
int Ecnt = 0;
string Etypname[110], Eelename[110];
int Eaddr[110];
int nowaddr = 0;
Type* EP[110];
int up(int n, int k){
	return n / k + (n % k > 0);
}
void upaddr(int &n, int k){
	n = up(n, k) * k;
}
bool isbasic(string s){
	if(s == "byte" || s == "short" || s == "int" || s == "long")	return true;
	return false;
}
unordered_map<string, Type*> tp;
void initbasic(){
	tp["byte"] = new Type;
	tp["short"] = new Type;
	tp["int"] = new Type;
	tp["long"] = new Type;
	tp["byte"] -> align = tp["byte"] -> size = 1;
	tp["short"] -> align = tp["short"] -> size = 2;
	tp["int"] -> align = tp["int"] -> size = 4;
	tp["long"] -> align = tp["long"] -> size = 8;
}
struct Element{
	string type;
	string name;
	int pos;
	Element(){
		pos = 0;
	}
};
void build();
void insert();
int getaddrbyname(string);
void getnamebyaddr();
signed main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	initbasic();
	cin >> T;
	while(T--){
		int op;
		cin >> op;
		if(op == 1)	build();
		else if(op == 2)	insert();
		else if(op == 3){
			string name;
			cin >> name;
			cout << getaddrbyname(name) << endl;
		}
		else	getnamebyaddr();
	}
	return 0;
}
void build(){
	string typname;
	cin >> typname;
	int k;
	cin >> k;
	int addr = 0;
	Type* typ = tp[typname] = new Type;
	typ -> cnt = k;
	for(int i = 1 ; i <= k ; i++){
		string sontypname, sonelename;
		cin >> sontypname >> sonelename;
		typ -> sontype[i] = sontypname;
		typ -> sonname[i] = sonelename;
		typ -> align = max(typ -> align, tp[sontypname] -> align);
		upaddr(addr, tp[sontypname] -> align);
		typ -> pos[i] = addr;
		addr += tp[sontypname] -> size;
	}
	upaddr(addr, typ -> align);
	typ -> size = addr;
	cout << typ -> size << ' ' << typ -> align << endl;
	return;
}
void insert(){
	string typname, elename;
	cin >> typname >> elename;
	upaddr(nowaddr, tp[typname] -> align);
	cout << nowaddr << endl;
	Ecnt++;
	Eaddr[Ecnt] = nowaddr;
	Etypname[Ecnt] = typname;
	Eelename[Ecnt] = elename;
	EP[Ecnt] = tp[typname];
	nowaddr += tp[typname] -> size;
}
int getaddrbyname(string name){
	int addr = 0;
	vector<string> vec;
	int idxtmp = 0, subtmp = 0;
	for(int i = 0 ; i < name.size() ; i++){
		if(name[i] == '.'){
			vec.push_back(name.substr(idxtmp, subtmp));
			subtmp = 0;
			idxtmp = i + 1;
		}
		else{
			subtmp++;
		}
	}
	vec.push_back(name.substr(idxtmp, subtmp));
	Type* Tp;
	for(int k = 0 ; k < vec.size() ; k++){
		string noww = vec[k];
		if(k == 0){
			for(int i = 1 ; i <= Ecnt ; i++){
				if(Eelename[i] == noww){
					Tp = tp[Etypname[i]];
					addr = Eaddr[i];
					break;
				}
			}
		}
		else{
			for(int i = 1 ; i <= Tp -> cnt ; i++){
				if(Tp -> sonname[i] == noww){
					addr += Tp -> pos[i];
					Tp = tp[Tp -> sontype[i]];
					break;
				}
			}
		}
	}
	return addr;
}
string ans = "";
void jump(Type* Tp, int addr){
	for(int i = 1 ; i <= Tp -> cnt ; i++){
		Type* tmp = tp[Tp -> sontype[i]];
		if(Tp -> pos[i] <= addr && Tp -> pos[i] + tmp -> size > addr){
			ans += Tp -> sonname[i];
			if(!isbasic(Tp -> sontype[i])){
				ans += '.';
				jump(tmp, addr - Tp -> pos[i]);
			}
			return;
		}
	}
	ans = "ERR";
	return;
}
void getnamebyaddr(){
	ans = "";
	int inaddr;
	cin >> inaddr;
	for(int i = 1 ; i <= Ecnt ; i++){
		Type* tmp = tp[Etypname[i]];
		if(Eaddr[i] <= inaddr && Eaddr[i] + tmp -> size > inaddr){
			ans += Eelename[i];
			if(!isbasic(Etypname[i]))	ans += ".", jump(tmp, inaddr - Eaddr[i]);
			cout << ans << endl;
			return;
		}
	}
	cout << "ERR" << endl;
	return;
}