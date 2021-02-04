#include<bits/stdc++.h>
using namespace std;
long long cnt[35];
int main()
{
    long long T,x,n,a;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&x,&n);
        memset(cnt,0,sizeof cnt);
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            if(x&a) x^=a;
            else    ++cnt[(long long)log2(a)];
        }
        for(long long i=0;i<=30;i++)
        {
            if(!((1ll<<i)&x)) continue;
            long long want = 1ll<<i;
            for(long long j=i;j>=0;j--)
            {
                while(cnt[j]&&(1ll<<j)<=want) want-=(1ll<<j),cnt[j]--;
            }
            if(!want)   x^=(1ll<<i);
        }
        long long ans = 0;
        for(long long i=30;i>=0;i--)
        {
            if(!((1ll<<i)&x)) continue;
            for(long long j=i+1;j<=30;j++)
            {
                if(cnt[j])  {ans=(1ll<<j)/(x&-x);x^=(1ll<<i);break;}
            }
        }
        printf(x ? "-1\n" : "%lld\n",ans);
    }
    return 0;
}
/*
3
10 3
1 32 1
23 4
16 1 4 1
20 5
2 1 16 1 8
*/
