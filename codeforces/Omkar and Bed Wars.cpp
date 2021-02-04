#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[N][2][2][2];
char s[N];
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %s",&n,s+1);
        for(int i=1;i<=n;i++)   a[i] = (s[i]=='L');
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    if(i!=j)    dp[2][i][j][k] = 1e9;
                    else        dp[2][i][j][k] = (j!=a[1])+(k!=a[2]);
                }
            }
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    dp[i][0][j][k] = 1e9;
                    dp[i][1][j][k] = 1e9;
                    if(j!=k||j!=0)
                    {
                        dp[i][0][j][k] = min(dp[i-1][0][0][j]+(a[i]!=k),dp[i][0][j][k]);
                        dp[i][1][j][k] = min(dp[i-1][1][0][j]+(a[i]!=k),dp[i][1][j][k]);
                    }
                    if(j!=k||j!=1)
                    {
                        dp[i][0][j][k] = min(dp[i-1][0][1][j]+(a[i]!=k),dp[i][0][j][k]);
                        dp[i][1][j][k] = min(dp[i-1][1][1][j]+(a[i]!=k),dp[i][1][j][k]);
                    }
                }
            }
        }
        int mn = 1e9;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++)    for(int k=0;k<2;k++)    if(i!=k||j!=k)  mn = min(mn,dp[n][i][j][k]);
        printf("%d\n",mn);
    }
    return 0;
}
/*
5
4
RLRL
6
LRRRRL
8
RLLRRRLL
12
LLLLRRLRRRLL
5
RRRRR

1
6
LRRRRL
*/
