#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int sz[N];
vector< int > g[N];
void getsz(int u,int p = -1)    {sz[u]=1;for(auto &x:g[u])if(x!=p)getsz(x,u),sz[u]+=sz[x];}
int main()
{
    return 0;
}
