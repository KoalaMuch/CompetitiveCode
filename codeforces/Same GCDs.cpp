#include<bits/stdc++.h>
using namespace std;
vector< long long > ft;
long long dp[1000005];
long long cal(long long l,long long r,long long d)
{
    return r/d-(l-1)/d;
}
int main()
{
    long long q,a,m;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&a,&m);
        long long G = __gcd(a,m),sq = sqrt(m),tmp=m;
        for(long long i=2;i<=sq;i++)
        {
            if(m%i==0&&m/i!=i)  ft.push_back(i),ft.push_back(m/i);
            else if(m%i==0)     ft.push_back(i);
        }
        ft.push_back(m),ft.push_back(1);
        sort(ft.begin(),ft.end());
        long long ans=0,sz = ft.size();
        for(long long i=sz-1;i>=0;i--)
        {
            dp[i] = cal(a,a+m-1,ft[i]);
            for(long long j=i+1;j<sz;j++) if(ft[j]%ft[i]==0)    dp[i]-=dp[j];
            if(ft[i]==G)    ans = dp[i];
        }
        printf("%lld\n",ans);
        ft.clear();
    }
    return 0;
}
