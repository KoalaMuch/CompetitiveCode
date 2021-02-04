#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N][N];
int dp[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i][i]),dp[i][i] = 1;
    for(int l=2;l<=n;l++)
    {
        for(int i=1,j=l;j<=n;i++,j++)
        {
            dp[i][j] = 1e9;
            for(int k=i;k<j;k++)
            {
                if(dp[i][k]==1&&dp[k+1][j]==1&&a[i][k]==a[k+1][j])  dp[i][j] = 1,a[i][j] = a[i][k]+1;
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
