#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5e4+5;
long long fac[N];
int main()
{
    long long n,m,ans = 0;
    scanf("%lld %lld",&n,&m);
    fac[0] = 1;
    for(long long i=1;i<=n;i++)   fac[i] = i*fac[i-1]%m;
    for(long long i=1;i<=n;i++)   ans = (ans+(((n-i+1)*fac[i]%m)*fac[n-i+1]%m))%m;
    printf("%lld\n",ans%m);
    return 0;
}
