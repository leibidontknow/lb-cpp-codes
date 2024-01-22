/*************************************************************************
	> File Name: E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
char str[1919810];
int main(){
	while(t--){
		cin >> str + 1;
		int n = strlen(str + 1);
		int prelen = 0;
		while(prelen < n / 2 + 1 && str[prelen + 1] == str[n - prelen])	prelen++;
		char 
	int l=-1,r=-1;
	int cnt=0;
	cin>>tmp;
	n=strlen(tmp);
	for(int i=0;i<n;i++){
		s[i*2+1]=tmp[i];
	}
	n=n*2+1;
	for(int i=0;i<n;i++){
		if(i>r){
			d[i]=1;
		}
		else{
			d[i]=min(d[l+r-i],r-i+1);
		}
		while(i-d[i]>=0&&i+d[i]<n&&s[i-d[i]]==s[i+d[i]])	d[i]++;
		if(i+d[i]-1>r){

			r=i+d[i]-1;
			l=i-d[i]+1;
		}
	}
	}
}
