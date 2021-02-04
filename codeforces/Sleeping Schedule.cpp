#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N];
int cal(int l,int r,int x)
{
    return x>=l&&x<=r;
}
int main()
{
    int n,h,l,r;
    scanf("%d %d %d %d",&n,&h,&l,&r);
    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        for(int j=0;j<h;j++)
        {
            if(dp[i-1][j]!=-1)
            {
                dp[i][(j+x)%h] = max(dp[i][(j+x)%h],dp[i-1][j]+cal(l,r,(j+x)%h));
                dp[i][(j+x-1)%h] = max(dp[i][(j+x-1)%h],dp[i-1][j]+cal(l,r,(j+x-1)%h));
            }
        }
    }
    int ans = 0;
    for(int j=0;j<h;j++)    ans = max(ans,dp[n][j]);
    printf("%d\n",ans);
    return 0;
}
