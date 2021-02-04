#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int N = 40005;
const int W = 1e6+5;
vector< pair< long long ,long long  > > weight[W];
long long p[N];
long long sz[N];
stack< pair< long long , long long > > st;
long long fin(long long i)
{
    return p[i]==i ? i : fin(p[i]);
}
long long Merge(long long u,long long v)
{
    st.push({u,v});
    if(sz[u]<sz[v]) p[u] = v,sz[v]+=sz[u];
    else            p[v] = u,sz[u]+=sz[v];
}
void split()
{
    while(!st.empty())
    {
        long long u = st.top().first,v = st.top().second;
        if(sz[u]<sz[v]) sz[v]-=sz[u],p[u] = u;
        else            sz[u]-=sz[v],p[v] = v;
        st.pop();
    }
}
long long solve1(long long i)
{
    long long u,v;
    if(weight[i].size()<1)  return split(),0;
    u = fin(weight[i][0].first),v = fin(weight[i][0].second);
//    if(i==2)    printf("--");
    if(u==v)    return split(),0;
    return 1;
}
long long solve2(long long i)
{
    long long u,v;
    if(weight[i].size()<2)  return split(),0;
    u = fin(weight[i][1].first),v = fin(weight[i][1].second);
    if(u==v)    return split(),0;
//    if(i==2)    printf("--");
    return 1;
}
long long solve3(long long i)
{
    long long u,v;
    if(weight[i].size()<3)  return split(),0;
    u = fin(weight[i][2].first),v = fin(weight[i][2].second);
    if(u==v)    return split(),0;
    return 1;
}
long long solve12(long long i)
{
    long long u,v;
    if(weight[i].size()<2)  return split(),0;
    u = fin(weight[i][0].first),v = fin(weight[i][0].second);
    if(u==v)    return split(),0;
    Merge(u,v);
    u = fin(weight[i][1].first),v = fin(weight[i][1].second);
    if(u==v)    return split(),0;
    split();
    return 1;
}
long long solve13(long long i)
{
    long long u,v;
    if(weight[i].size()<3)  return split(),0;
    u = fin(weight[i][0].first),v = fin(weight[i][0].second);
    if(u==v)    return split(),0;
    Merge(u,v);
    u = fin(weight[i][2].first),v = fin(weight[i][2].second);
    if(u==v)    return split(),0;
    split();
    return 1;
}
long long solve23(long long i)
{
    long long u,v;
    if(weight[i].size()<3)  return split(),0;
    u = fin(weight[i][1].first),v = fin(weight[i][1].second);
    if(u==v)    return split(),0;
    Merge(u,v);
    u = fin(weight[i][2].first),v = fin(weight[i][2].second);
    if(u==v)    return split(),0;
    split();
    return 1;
}
long long solve123(long long i)
{
    long long u,v;
    if(weight[i].size()<3)  return split(),0;
    u = fin(weight[i][0].first),v = fin(weight[i][0].second);
    if(u==v)    return split(),0;
    Merge(u,v);
    u = fin(weight[i][1].first),v = fin(weight[i][1].second);
    if(u==v)    return split(),0;
    Merge(u,v);
    u = fin(weight[i][2].first),v = fin(weight[i][2].second);
    if(u==v)    return split(),0;
    split();
    return 1;
}
int main()
{
    long long  n,m,s = 0,s2 = 1,u,v,w;
    scanf("%lld %lld",&n,&m);
    for(long long  i=1;i<=n;i++)   p[i] = i,sz[i] = 1;
    for(long long  i=1;i<=m;i++) scanf("%lld %lld %lld",&u,&v,&w),weight[w].push_back({u,v});
//    printf("%d\n",weight[4].size());
    for(long long  i=1;i<=1000000;i++)
    {
        if(weight[i].size()==0) continue;
        long long cnt = 0,SZ = weight[i].size();
        if(!cnt)
        {
            if(SZ>=3)   cnt = solve123(i);
            if(cnt) s=(s+3*i)%mod;
        }
        if(!cnt)
        {
            if(SZ>=2)   cnt += solve12(i);
            if(SZ>=3)   cnt += solve13(i)+solve23(i);
            if(cnt) s=(s+2*i)%mod;
        }
//        if(i==2)    printf("%lld %lld %lld %lld\n",fin(1),fin(2),fin(3),fin(4));
        if(!cnt)
        {
            if(SZ>=1)   cnt+=solve1(i);
            if(SZ>=2)   cnt+=solve2(i);
            if(SZ>=3)   cnt+=solve3(i);
            if(cnt) s=(s+i)%mod;
        }
        if(!cnt)    cnt = 1;
        for(long long j=0;j<weight[i].size();j++)
        {
            u = fin(weight[i][j].first),v = fin(weight[i][j].second);
            if(u!=v)    Merge(u,v),st.pop();
        }
        s2 = s2*cnt%mod;
    }
    printf("%lld %lld\n",s,s2);
    return 0;
}
/*
4 5
1 3 2 2 3 2 1 2 1 3 4 1 1 4 2

4 5
1 2 1
1 3 1
2 3 2
2 4 2
3 4 2

4 5
1 2 2
1 3 2
2 3 1
2 4 1
3 4 1

4 5
1 2 1
3 4 1
1 3 3
1 4 2
2 3 2
*/
