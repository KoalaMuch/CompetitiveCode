#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[N];
vector< int > g[N];
int a[N];
void get_dp(int u,int p = 0)
{
    dp[u] = (a[u]) ? 1 : -1;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        get_dp(x,u);
        if(dp[x]>=0)    dp[u]+=dp[x];
    }
}
void reroot(int u,int p = 0)
{
    if(p)
    {
        if(dp[u]>=0)    dp[u] = max(dp[u],dp[p]);
        else            dp[u] += max(dp[p],0);
    }
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        reroot(x,u);
    }
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",a+i);
    for(int i=1;i<n;i++)    scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    get_dp(1);
    reroot(1);
    for(int i=1;i<=n;i++)   printf("%d ",dp[i]);
    return 0;
}
