/*************************************************************************
	> File Name: E.cpp
	> Author: lbdontknow
	> Mail: lbdontknow@163.com 
	> God bless no BUG 
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m;
int head[N], nxt[N], to[N];
void add(int u, int v){
	static int cnt = 0;
	to[++cnt] = v;

}
