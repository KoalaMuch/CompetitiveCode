/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long binpow(long long n,long long base = 2)
{
    long long res = 1;
    for(long long i=0;i<=63;i++,base = base*base%mod) if(n&(1ll<<i))  res = res*base%mod;
    return res;
}
int main()
{
    long long q,n;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&n);
        if(n<3) printf("%lld\n",binpow(n));
        else    printf("%lld\n",(binpow(n)-binpow(n-3)+mod)%mod);
    }
    return 0;
}
