/*************************************************************************
	> File Name: B.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> Created Time: 2023年08月07日 星期一 23时43分12秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		int last=-1;
		string tmp;
		cin>>tmp;
		string ss="0"+tmp;
		for(int i=ss.length()-1;i>=0;i--){
			if(ss[i]>='5'){
				ss[i]='0';
				ss[i-1]++;
				last=i;
			}
		}
		if(last==-1){
			last=ss.length();
		}
		if(ss[0]!='0')	cout<<ss[0];
		for(int i=1;i<last;i++)	cout<<ss[i];
		for(int i=last;i<ss.length();i++)	cout<<"0";
		cout<<endl;
	}
	return 0;
}
