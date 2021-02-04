#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int main()
{
    long long f = 1,n,ans = 0;
    scanf("%lld",&n);
    for(long long i=0;i<=n;i++)
    {
        if((n-i)%2)  ans = (ans-f+mod)%mod;
        else         ans = (ans+f)%mod;
        f=f*(n-i)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
