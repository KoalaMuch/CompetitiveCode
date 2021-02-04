#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][7];
int a[N];
int main()
{
    int q,n,lim,z;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 0;
        scanf("%d %d %d",&n,&lim,&z);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=5;j++)
            {
                dp[i][j] = dp[i-1][j]+a[i];
                for(int k=0;k<=j;k++)
                {
                    if(i<n) dp[i][j] = max(dp[i][j],dp[i-1][j-k]+(1+k)*a[i]+k*a[i+1]);
                }
                /*dp[i][j] = dp[i-1][j]+a[i];
                if(i<n&&j>0) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+2*a[i]+a[i+1]);*/
                if(i+2*j-1==lim&&j<=z)    ans = max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
5
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
5 4 2
8 8 5 5 2
*/
