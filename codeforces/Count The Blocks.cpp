#include<bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
long long binpow(long long a,long long b)
{
    if(b<0) return 0;
    long long ret = 1;
    while(b)
    {
        if(b&1) ret = ret*a%mod;
        b >>= 1;
        a = a*a%mod;
    }
    return ret;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        long long ans = 0;
        if(i==n)    return printf("10\n"),0;
        if(n-i-1>=0)    ans = (810*(n-i-1)%mod)*binpow(10,n-i-2);
        ans+=180*binpow(10,n-i-1)%mod;
        printf("%lld ",ans%mod);
    }
    return 0;
}
