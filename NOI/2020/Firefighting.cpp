#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
vector< int > g[N];
vector< int > ans;
bool mark[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)   scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    return 0;
}
