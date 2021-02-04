#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long v[N];
long long out[N];
struct A
{
    long long v,idx,out;
    bool operator<(const A&o)const
    {
        return v<o.v;
    }
};
priority_queue< A > pq1[N];
vector< A > all[N];
int main()
{
    long long n,w,s=0;
    scanf("%lld %lld",&n,&w);
    w+=2;
    for(long long i=1;i<=n;i++)   v[i] = -1e10;
    for(long long i=1;i<=n;i++)
    {
        long long x,num;
        scanf("%lld",&x);
        all[0].push_back({0,i,w-x-1});
        for(long long j=1;j<=x;j++)   scanf("%lld",&num),all[j].push_back({num,i,j+w-x-1});
        all[x+1].push_back({0,i,w+1});
    }
    for(long long i=0;i<=w;i++)
    {
        for(auto &x:all[i])
        {
            pq1[x.idx].push(x);
            if(pq1[x.idx].top().v>v[x.idx]||out[x.idx]<=i)
            {
                if(v[x.idx]!=-1e10) s-=v[x.idx];
                s+=pq1[x.idx].top().v;
                v[x.idx] = pq1[x.idx].top().v;
                out[x.idx] = pq1[x.idx].top().out;
                pq1[x.idx].pop();
            }
        }
        if(i&&i<=w-2)   printf("%lld ",s);
    }
    return 0;
}
