#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long gcd(long long a,long long b)
{
    if(!b)  return a;
    return gcd(b,a%b);
}
long long a[N];
int main()
{
    long long t,n,k;
    scanf("%lld",&t);
    while(t--)
    {
        bool ch = 0;
        scanf("%lld %lld",&n,&k);
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        long long g = a[2]-a[1];
        for(long long i=2;i<=n;i++)   g = gcd(g,a[i]-a[i-1]);
        for(long long i=1;i<=n;i++)   if(abs(a[i]-k)%g==0)    ch = 1;
        printf(ch ? "YES\n" : "NO\n");
    }
    return 0;
}
