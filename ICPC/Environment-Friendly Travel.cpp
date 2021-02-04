#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 105;
long long dp[N][M];
vector< pair< long long,long long > > g[N];
long long c[M];
pair< long long,long long > x[N];
long long sq[21005];
struct A
{
    long long i,dis,w;
    bool operator<(const A&o)const
    {
        if(w!=o.w)  return w>o.w;
        return dis>o.dis;

    }
};
priority_queue< A > pq;
long long cal(long long i,long long j)
{
    return (x[i].first-x[j].first)*(x[i].first-x[j].first)+
           (x[i].second-x[j].second)*(x[i].second-x[j].second);
}
int main()
{
    long long sx,sy,dx,dy,B,t,n;
    scanf("%lld %lld %lld %lld %lld %lld %lld",&sx,&sy,&dx,&dy,&B,&c[0],&t);
    for(long long i=1;i<=t;i++)   scanf("%lld",&c[i]);
    scanf("%lld",&n);
    x[0] = {sx,sy};
    x[n+2] = {dx,dy};
    for(long long i=1;i<=n;i++)
    {
        long long l;
        scanf("%lld %lld %lld",&x[i].first,&x[i].second,&l);
        for(long long j=1;j<=l;j++)
        {
            long long a,b;
            scanf("%lld %lld",&a,&b);
            g[i].push_back({a+1,b});
            g[a+1].push_back({i,b});
        }
        g[0].push_back({i,0});
        g[i].push_back({n+2,0});
    }
    g[0].push_back({n+2,0});
    for(long long i=1;i<=21000;i++)
    {
        if(i>sq[i-1]*sq[i-1])   sq[i] = sq[i-1]+1;
        else                    sq[i] = sq[i-1];
    }
    for(long long i=0;i<=B;i++)
    {
        for(long long j=0;j<=n+2;j++)
        {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    pq.push({0,0,0});
    while(!pq.empty())
    {
        long long nowi = pq.top().i,nowdis = pq.top().dis,noww = pq.top().w;pq.pop();
        if(nowi==n+2)
        {
            printf("%lld\n",noww);
            return 0;
        }
        for(auto &k:g[nowi])
        {
            long long dis = sq[cal(nowi,k.first)];
            if(nowdis+dis>B)    continue;
            if(dp[nowdis][nowi]+dis*c[k.second]<dp[nowdis+dis][k.first])
            {
                dp[nowdis+dis][k.first] = dp[nowdis][nowi]+dis*c[k.second];
                pq.push({k.first,nowdis+dis,dp[nowdis+dis][k.first]});
            }
        }
    }
    printf("-1\n");
    return 0;
}
