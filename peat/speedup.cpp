#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long v,w,pre,speed,cnt;
    bool operator<(const A&o) const
    {
        return w>o.w;
    }
};
A now;
long long spi[15]= {1,2,4,8,16,32,64,128,256};
vector<A> g[80010];
priority_queue<A> pq;
long long dis[80010][12][12];
long long por[80010];
int main()
{
    long long n,m,l,q,u,v,w,minn=1e18;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&q);
    for(long long i=1; i<=n; i++)
        for(long long j=0; j<=q; j++)
            for(long long k=0;k<=l;k++)
                dis[i][j][k]=1e18;
    for(long long i=1; i<=m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
    }
    long long cnt = 0;
    for(long long i=1; i<=l; i++)
    {
        long long city;
        scanf("%lld",&city);
        por[city]=++cnt;
    }
    pq.push({1,0,0,0,0});
    dis[1][0][0]=0;
    while(!pq.empty())
    {
        now=pq.top();
        pq.pop();
        for(auto &x:g[now.v])
        {
            if(por[now.v]!=0 && now.cnt<q && now.pre!=por[now.v])
            {
                if(now.w+(x.w/spi[now.speed+1])<dis[x.v][now.cnt+1][por[now.v]])
                {
                    dis[x.v][now.cnt+1][por[now.v]]=now.w+(x.w/spi[now.speed+1]);
                    pq.push({x.v,dis[x.v][now.cnt+1][por[now.v]],por[now.v],now.speed+1,now.cnt+1});
                }
            }
            if(now.w+(x.w/spi[now.speed])<dis[x.v][now.cnt][now.pre])
            {
                dis[x.v][now.cnt][now.pre]=now.w+(x.w/spi[now.speed]);
                pq.push({x.v,dis[x.v][now.cnt][now.pre],now.pre,now.speed,now.cnt});
            }
        }
    }
    for(long long i=0; i<=q; i++)
    {
        for(long long j=0;j<=l;j++)
            minn=min(minn,dis[n][i][j]);
    }
    printf("%lld\n",minn);
    return 0;

}
