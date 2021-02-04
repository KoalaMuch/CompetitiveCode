#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int N = 1005;
long long dp[2][N][N];
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        for(long long j=n;j>=i;j--)
        {
            dp[1][i][j] =(1+dp[1][i][j+1]+dp[1][i-1][j])%mod;
            if(i<=j+1&&i-1<=j)  dp[1][i][j]= (dp[1][i][j]-dp[1][i-1][j+1]+mod)%mod;
//            printf("%lld %lld %lld\n",i,j,dp[1][i][j]);
        }
    for(long long i=2;i<=m;i++)
        for(long long j=1;j<=n;j++)
            for(long long k=n;k>=j;k--)
            {
                dp[i%2][j][k] = (dp[(i-1)%2][j][k]+dp[i%2][j-1][k]+dp[i%2][j][k+1])%mod;
                if(j-1<=k&&j<=k+1)  dp[i%2][j][k] = (dp[i%2][j][k]-dp[i%2][j-1][k+1]+mod)%mod;
//                printf("%lld %lld %lld\n",j,k,dp[i%2][j][k]);
            }
    long long ans = 0;
    for(long long i=1;i<=n;i++) ans = (ans+dp[m%2][i][i]-dp[m%2][i-1][i]+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
