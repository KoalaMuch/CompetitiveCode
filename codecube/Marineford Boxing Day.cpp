#include<bits/stdc++.h>
using namespace std;
long long solve(long long a,long long b,long long c)
{
    long long G = __gcd(a,__gcd(b,c));
    if(G!=1)    return solve(a/G,b/G,c/G)*G;
    return max(a,max(b,c))+min(a,min(b,c))-1;
}
int main()
{
    long long a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld\n",solve(a,b,c));
    return 0;
}
