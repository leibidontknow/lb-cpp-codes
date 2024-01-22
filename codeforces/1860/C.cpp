/*************************************************************************
	> File Name: C.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[1919810],rr[1919810];
int sum = 0;
void msort(int l,int r){
	if(l==r)	return;
	int mid=(l+r)/2;
	int i=l,j=mid+1;
	msort(i,mid);
	msort(j,r);
	int k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			rr[k]=a[i];
			k++;
			i++;
		}
		else{
			rr[k]=a[j];
			k++;
			j++;
			sum+=mid-i+1;
		}
	}
	while(i<=mid){
		rr[k]=a[i];
		i++;
		k++;
	}
	while(j<=r){
		rr[k]=a[j];
		j++;
		k++;
	}
	for(i=l;i<=r;i++){
		a[i]=rr[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		sum = 0;
		cin >> n;
		for(int i = n ; i >= 1 ; i--){
			cin >> a[i];
		}
		msort(1, n);
		cout << sum / 2 << endl;
	}
	return 0;
}
