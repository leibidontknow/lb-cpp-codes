#include<bits/stdc++.h>
using namespace std;
#define max(a,b)    [](int c,int d){return c > d ? c : d;}(a,b)
#define min(a,b)    [](int c,int d){return c < d ? c : d;}(a,b)


inline void read(long long &tar)
{
    long long x = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)) f = (ch == '-' ? -1 : 1),ch = getchar();
    while(isdigit(ch))  x = (x << 1)+(x << 3) + (ch ^ 48),ch = getchar();
    tar = x * f;
}
template<typename T,typename... Args>
inline void read(T &tar,Args... &args)
{
    read(tar);
    read(args...);
}
