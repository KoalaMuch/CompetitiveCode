#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long cycle[N];
long long sumcycle[N];
long long id[N];
long long mk[N];
long long mx[N];
long long from[N];
long long dgin[N];
long long sum[N];
long long to[N];
long long v[N];
queue< long long > q;
int main()
{
    long long T,n,k;
    scanf("%lld",&T);
    while(T--)
    {
        long long cnt = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)   scanf("%lld %lld",&to[i],&v[i]),++dgin[to[i]];
        scanf("%lld",&k);
        for(long long i=1;i<=n;i++)
        {
            if(!dgin[i])
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            long long u = q.front();    q.pop();
            sum[u]+=v[u];
            --dgin[to[u]];
            if(sum)
            sum[to[u]]+=sum[u];
            if(!dgin[to[u]])    q.push(to[u]);
        }
        for(long long i=1;i<=n;i++)
        {
            if(dgin[i]&&!cycle[i])
            {
                long long u = i;
                ++cnt;
                sumcycle[cnt]+=v[u];
                cycle[u] = cnt;
                while(to[u]!=i) cycle[to[u]] = cnt,sumcycle[cnt]+=v[to[u]],u = to[u];
            }
        }
        for(long long i=1;i<=n;i++)
        {
            if(!dgin[i]&&cycle[to[i]]&&sum[i]>mx[cycle[to[i]]]) mx[cycle[to[i]]] = sum[i],mk[id[cycle[to[i]]]] = 0,mk[i] = 1,id[cycle[to[i]]] = i;
        }
        for(long long i=1;i<=cnt;i++) sumcycle[i]+=mx[i];
        for(long long i=1;i<=n;i++)
        {
            if(!dgin[i]&&cycle[to[i]]&&!mk[i])    sumcycle[++cnt] = sum[i];
        }
        sort(sumcycle+1,sumcycle+cnt+1,greater<long long>());
        long long ans = 0;
        for(long long i=1;i<=k+1;i++) ans+=sumcycle[i];
        printf("%lld\n",ans);
        if(T)
        {
            for(long long i=1;i<=n;i++) cycle[i] = dgin[i] = sumcycle[i] = id[i] = mk[i] = mx[i] = sum[i] = 0;
        }
    }
    return 0;
}
/*
2
5
2 5
4 7
4 6
5 3
2 9
0
5
2 5
4 7
4 6
5 3
2 9
1
*/
