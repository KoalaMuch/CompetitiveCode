#include<bits/stdc++.h>
using namespace std;
const int N = 6e5+5;
long long dp[N];
long long a[N];
long long b[N];
long long c[N];
int main()
{
    long long T,n;
    scanf("%lld",&T);
    while(T--)
    {
        long long ans = 1e18;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)   scanf("%lld %lld",&a[i],&b[i]),a[i+n] = a[i],b[i+n] = b[i];
        for(long long i=1;i<=2*n;i++)
        {
            c[i] = max(0ll,a[i]-b[i-1]);
            dp[i] = dp[i-1]+c[i];
            if(i>=n)    ans = min(ans,dp[i]-dp[i-n]+min(a[i-n+1],b[i-n]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
