#include<bits/stdc++.h>
using namespace std;
const int N = 35;
long long dp[N][N];
int p2[N];
int main()
{
    int T,d,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&d,&m);
        int n = (int)log2(d)+1;
        long long ans = 0;
        p2[0] = 1;
        for(int i=1;i<=n;i++)   p2[i] = p2[i-1]*2%m;
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                dp[i][j] = 0;
                for(int k=j-1;k>=0;k--)
                {
                    int mul;
                    if(j==n) mul = d-p2[j-1]+1;
                    else     mul = p2[j-1];
                    dp[i][j] = (dp[i][j]+(mul*dp[i-1][k]%m))%m;
                }
                ans = (ans+dp[i][j])%m;
            }
        }
//        if(d==2)    printf("%lld %lld %lld %d\n",dp[1][1],dp[1][2],dp[2][2],n);
        printf("%lld\n",ans);
    }
    return 0;
}
