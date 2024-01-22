/*************************************************************************
	> File Name: A.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月07日 星期一 23时32分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		int ji=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x&1)	ji++;
		}
		if(ji&1)	puts("NO");
		else puts("YES");
	}
}
