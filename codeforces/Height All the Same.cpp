#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long binpow(long long a,long long b,long long ret = 1)
{
    if(!a)  return 0;
    while(b)
    {
        if(b&1) ret = ret*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return ret;
}
long long cal(long long n,long long m,long long r)
{
    if(r==1)    return 1; //special case
    if((n*m)&1) return binpow(r,n*m);
    return (binpow(r,n*m)+(r%2))*binpow(2,mod-2)%mod;
}
int main()
{
    long long n,m,l,r;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&r);
    printf("%lld\n",cal(n,m,r-l+1));
    return 0;
}
/*
1 2 5 5
*/
