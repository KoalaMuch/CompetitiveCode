#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int K = 105;
int dp[N][K];
struct A
{
    int u,w,use;
    bool operator<(const A&o)const
    {
        return w>o.w;
    }
};
vector< A > g[N];
priority_queue< A > pq;
int main()
{
    int n,m,k,mn = 1e9;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++) scanf("%d %d %d",&u,&v,&w),g[u].push_back({v,w,0}),g[v].push_back({u,w,0});
    for(int i=1;i<=n;i++)   for(int j=0;j<=k;j++)   dp[i][j] = 1e9;
    dp[1][0] = 0;
    pq.push({1,0,0});
    while(!pq.empty())
    {
        int u = pq.top().u,w = pq.top().w,use = pq.top().use; pq.pop();
        if(u==n)    mn = min(mn,w);
        if(u==n&&use==0)  return printf("%d\n%d\n%d\n",w,mn,w-mn),0;
        for(auto &x:g[u])
        {
            if(w+x.w<dp[x.u][use])
            {
                dp[x.u][use] = w+x.w;
                pq.push({x.u,w+x.w,use});
            }
            if(use<k&&w+x.w/2<dp[x.u][use+1])
            {
                dp[x.u][use+1] = w+x.w/2;
                pq.push({x.u,w+x.w/2,use+1});
            }
        }
    }
    return 0;
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
