#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N = 2e5+5;
long long inv[N];
long long fac[N];
long long mow(long long a,long long b)
{
    long long ret = 1;
    for(long long i=0;i<=62;i++,a = a*a%mod)
    {
        if((1ll<<i&b)) ret = ret*a%mod;
    }
    return ret;
}
int main()
{
    fac[0] = inv[0] = 1;
    long long n,m,ans = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++)   fac[i] = fac[i-1]*i%mod,inv[i] = mow(fac[i],mod-2);
    if(n==2)    return puts("0"),0;
    for(long long i=2;i<=m;i++)
    {
        if(i-1<n-2) continue;
        ans = (ans+((fac[i-1]*inv[n-2]%mod)*inv[i-n+1]%mod))%mod;
    }
    printf("%lld\n",(ans*mow(2,n-3)%mod)*(n-2)%mod);
}
