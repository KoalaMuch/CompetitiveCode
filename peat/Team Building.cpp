#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
const int P = 8;
long long dpk[N][1<<7];
long long dpp[P][1<<7][P];
long long dpl[N][1<<7];
long long s[N][7];
pair< long long,long long > a[N];
int main()
{
    long long n,p,k;
    scanf("%lld %lld %lld",&n,&p,&k);
    long long lim = (1<<p)-1;
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i].first),a[i].second=i,a[i].first*=-1;
    for(long long i=1;i<=n;i++)   for(long long j=0;j<p;j++)    scanf("%lld",&s[i][j]);
    sort(a+1,a+n+1);
    for(long long i=0;i<=n;i++) for(long long j=0;j<=lim;j++)   dpk[i][j] = -1e18;
    dpk[0][0] = 0;
    for(long long i=0;i<=p;i++) for(long long j=0;j<=lim;j++)   for(long long bit=0;bit<=p;bit++)   dpp[i][j][bit] = -1e18;
    dpp[0][0][0] = 0;
    for(long long i=0;i<=n;i++) for(long long j=0;j<=lim;j++)   dpl[i][j] = -1e18;
    dpl[k+p][0] = 0;
    for(long long i=1;i<=k;i++)
    {
        a[i].first*=-1;
        for(long long j=0;j<=lim;j++)
        {
            dpk[i][j] = dpk[i-1][j]+a[i].first;
            for(long long bit=0;bit<p;bit++)
            {
                if((1<<bit)&j)   dpk[i][j] = max(dpk[i][j],dpk[i-1][j^(1<<bit)]+s[a[i].second][bit]);
            }
        }
    }
    for(long long i=k+1;i<=k+p;i++)
    {
        a[i].first*=-1;
        for(long long j=0;j<=lim;j++)
        {
            for(long long l=0;l<=p;l++)
            {
                dpp[i-k][j][l] = dpp[i-k-1][j][l];
                if(l)   dpp[i-k][j][l] = max(dpp[i-k][j][l],dpp[i-k-1][j][l-1]+a[i].first);
                for(long long bit=0;bit<p;bit++)
                {
                    if((1<<bit)&j)  dpp[i-k][j][l] = max(dpp[i-k][j][l],dpp[i-k-1][j^(1<<bit)][l]+s[a[i].second][bit]);
                }
            }
        }
    }
    for(long long i=k+p+1;i<=n;i++)
    {
        a[i].first*=-1;
        for(long long j=0;j<=lim;j++)
        {
            dpl[i][j] = dpl[i-1][j];
            for(long long bit=0;bit<p;bit++)
            {
                if((1<<bit)&j)   dpl[i][j] = max(dpl[i][j],dpl[i-1][j^(1<<bit)]+s[a[i].second][bit]);
            }
        }
    }
    long long ans = 0;
    for(long long i=0;i<=lim;i++)
    {
        for(long long j=0;j<=lim;j++)
        {
            if(i&j)   continue;
            int biti = __builtin_popcount(i);
            ans = max(ans,dpk[k][i]+dpp[p][j][biti]+dpl[n][lim^(i|j)]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
