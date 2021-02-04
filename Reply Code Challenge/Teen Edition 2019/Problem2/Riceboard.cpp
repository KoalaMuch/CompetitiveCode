#include<bits/stdc++.h>
using namespace std;
long long binpow(long long a,long long b,long long c)
{
    long long ret = 1;
    for(long long i=0;i<=63;i++,a=a*a%c)
    {
        if((1ll<<i)&b)  ret = ret*a%c;
    }
    return ret%c;
}
long long modInverse(long long a, long long m)
{
    a = a%m;
    for (long long x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
int main()
{
    freopen("in5.txt","r",stdin);
    freopen("out5.txt","w",stdout);
    long long T,r,n,m;
    scanf("%lld",&T);
    for(long long X=1;X<=T;X++)
    {
        scanf("%lld %lld %lld",&r,&n,&m);
        long long g = __gcd(r-1,m);
        long long a = (binpow(r,n*n,m)-1+m)%m;
        long long b = modInverse((r-1)/g,m);
        if(r-1==0)  b = 1;
        printf("Case #%lld: %lld\n",X,a*b%m);
    }
    return 0;
}
/*
3
3 2 13
2 3 100
2 3 73
*/
