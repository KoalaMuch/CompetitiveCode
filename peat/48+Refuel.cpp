#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int F = 105;
int dp[N][F];
int cost[N];
struct A
{
    int u,w,fuel;
    bool operator<(const A&o)const
    {
        return w>o.w;
    }
};
vector< A > g[N];
priority_queue< A > pq;
int main()
{
    int T,n,m,capacity,s,e;
    scanf("%d",&T);
    while(T--)
    {
        int ch = 0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)   scanf("%d",&cost[i]);
        for(int i=0,u,v,w;i<m;i++)  scanf("%d %d %d",&u,&v,&w),g[u].push_back({v,w,0}),g[v].push_back({u,w,0});
        scanf("%d %d %d",&capacity,&s,&e);
        for(int i=0;i<n;i++)    for(int j=0;j<=capacity;j++)   dp[i][j] = 1e9;
        dp[s][0] = 0 ;
        pq.push({s,0,0});
        while(!pq.empty())
        {
            int u = pq.top().u,w = pq.top().w,fuel = pq.top().fuel; pq.pop();
            if(u==e)
            {
                ch = 1;
                printf("%d\n",w);
                break;
            }
            if(fuel<capacity&&w+cost[u]<dp[u][fuel+1])
            {
                dp[u][fuel+1] = w+cost[u];
                pq.push({u,w+cost[u],fuel+1});
            }
            for(auto &x:g[u])
            {
                if(fuel>=x.w&&w<dp[x.u][fuel-x.w])
                {
                    dp[x.u][fuel-x.w] = w;
                    pq.push({x.u,w,fuel-x.w});
                }
            }
        }
        for(int i=0;i<n;i++)    g[i].clear();
        if(!ch) printf("-99\n");
        while(!pq.empty())  pq.pop();
    }
    return 0;
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
20 1 4

*/
