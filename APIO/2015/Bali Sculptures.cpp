#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
long long dp[N];
long long a[N];
long long dp2[N];
int main()
{
    long long n,l,r,fix = 0;
    scanf("%lld %lld %lld",&n,&l,&r);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    for(long long bit=41;bit>=0;bit--)
    {
        for(long long i=1;i<=n;i++)
        {
            dp[i] = 1e9,dp2[i] = 0;
            long long s = 0;
            for(long long j=i;j>=1;j--)
            {
                s+=a[j];
                if(s-(s&fix)<(1ll<<bit)&&dp[j-1]+1<=r) dp[i] = min(dp[i],dp[j-1]+1),dp2[i] = max(dp2[i],dp2[j-1]+1);
            }
        }
        if(dp[n]==1e9||dp2[n]<l)  fix|=(1ll<<bit);
    }
    printf("%lld\n",fix);
    return 0;
}
/*
6 1 3
8 1 2 1 5 4

8 1 4
1 2 1 1 1 0 4 6
*/
