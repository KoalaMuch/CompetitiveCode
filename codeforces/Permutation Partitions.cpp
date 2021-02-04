#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int main()
{
    long long ans = 0,sol = 1,n,lst = 0,k,x;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        if(x>=n-k+1)
        {
            ans+=x;
            if(lst) sol = sol*(i-lst)%mod;
            lst = i;
        }
    }
    printf("%lld %lld\n",ans,sol);
    return 0;
}
