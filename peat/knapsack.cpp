#include<bits/stdc++.h>
using namespace std;
int dp[100][1000];
int w[100];
int v[100];
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    for(int i=1;i<=n;i++)   scanf("%d %d",&w[i],&v[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]); //choose i
        }
    }
    printf("%d\n",dp[n][W]);
    return 0;
}
