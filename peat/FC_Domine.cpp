#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
long long dp[N][N][10];
long long a[5];
int main()
{
    for(long long i=0;i<=1000;i++)   for(long long j=0;j<=1000;j++) for(long long k=0;k<=7;k++) dp[i][j][k] = -3e9;
    dp[0][0][0] = 0;
    long long n,K;
    scanf("%lld %lld",&n,&K);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&a[0],&a[1],&a[2]);
        long long lim = min(K,(3*i)/2);
        for(long long j=0;j<=lim;j++)
        {
            for(long long k=0;k<=7;k++)
            {
                long long s = 0;
                for(long long l=0;l<=2;l++) if(k&(1ll<<l))  s+=a[l];
                dp[i][j][k] = s+dp[i-1][j][0];
                if(!(k&1)&&j>=1)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-1][1]+a[0]);
                if(!(k&2)&&j>=1)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-1][2]+a[1]);
                if(!(k&4)&&j>=1)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-1][4]+a[2]);
                if(!(k&3)&&j>=1)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-1][0]+a[0]+a[1]);
                if(!(k&3)&&j>=2)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-2][3]+a[0]+a[1]);
                if(!(k&6)&&j>=1)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-1][0]+a[1]+a[2]);
                if(!(k&6)&&j>=2)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-2][6]+a[1]+a[2]);
                if(!(k&5)&&j>=2)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-2][5]+a[0]+a[2]);
                if(!(k&7)&&j>=3)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-3][7]+a[0]+a[1]+a[2]);
                if(!(k&7)&&j>=2)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-2][1]+a[0]+a[1]+a[2]);
                if(!(k&7)&&j>=2)  dp[i][j][k] = max(dp[i][j][k],s+dp[i-1][j-2][4]+a[0]+a[1]+a[2]);
            }
        }
    }
    printf("%lld\n",dp[n][K][0]);
    return 0;
}
/*
5 3
2 1 -1
1 3 2
0 2 3
2 1 1
3 3 0
*/
