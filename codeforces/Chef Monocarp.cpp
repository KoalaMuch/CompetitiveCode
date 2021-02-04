#include<bits/stdc++.h>
using namespace std;
const int N = 202;
int dp[N][N*2];
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 1e9;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",a+i);
        sort(a+1,a+n+1);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<=n*2;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=2*n;j++) //time put out
            {
                dp[i][j] = 1e9;
                for(int k=j-1;k>=0;k--)
                {
                    if(dp[i-1][k]!=-1)  dp[i][j] = min(dp[i][j],dp[i-1][k]+abs(a[i]-j));
                    if(i==n)    ans = min(ans,dp[i][j]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
