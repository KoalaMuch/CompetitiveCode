#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 3e5+5;
long long mow(long long a,long long b)
{
    if(b==1)    return a%mod;
    if(b==0)    return 0;
    long long now = mow(a,b/2);
    if(b&1) return (now*now%mod)*a%mod;
    return now*now%mod;
}
long long inv[N];
long long fac[N];
priority_queue< long long > q;
pair< long long,long long > p[N];
long long cnr(long long n,long long k)
{
    if(n<k) return 0;
    return (fac[n]*inv[n-k]%mod)*inv[k]%mod;
}
int main()
{
    long long n,k,ans = 0;
    fac[0] = inv[0] = 1;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)   scanf("%lld %lld",&p[i].first,&p[i].second),fac[i] = i*fac[i-1]%mod,inv[i] = mow(fac[i],mod-2);
    sort(p+1,p+n+1);
    for(long long i=1;i<=n;i++)
    {
        while(!q.empty()&&-q.top()<p[i].first)  q.pop();
        ans=(ans+cnr(q.size(),k-1))%mod;
        q.push(-p[i].second);
    }
    printf("%lld\n",ans);
    return 0;
}
