#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long dp[N];
long long from[N];
vector< long long > ans;
struct A
{
    long long u,w;
    bool operator<(const A&o)const
    {
        return w>o.w;
    }
};
priority_queue< A > pq;
vector< A > g[N];
int main()
{
    long long n,m,u,v,w;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++)   scanf("%lld %lld %lld",&u,&v,&w),g[u].push_back({v,w}),g[v].push_back({u,w});
    for(long long i=2;i<=n;i++)   dp[i] = 1e18;
    pq.push({1,0});
    while(!pq.empty())
    {
        u = pq.top().u,w = pq.top().w;
        pq.pop();
        for(auto &x:g[u])
        {
            if(dp[u]+x.w<dp[x.u])
            {
                from[x.u] = u;
                dp[x.u] = dp[u]+x.w;
                pq.push({x.u,dp[x.u]});
            }
        }
    }
    if(dp[n]==1e18) return puts("-1"),0;
    ans.push_back(n);
    while(from[n]!=0)  ans.push_back(fromน[n]),n = from[n];
    reverse(ans.begin(),ans.end());
    for(auto &x:ans)    printf("%lld ",x);
    return 0;
}
