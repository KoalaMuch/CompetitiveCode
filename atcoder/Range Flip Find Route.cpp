#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N];
char s[N][N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",s[i]+1);
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = 1e9;
            if(i==1&&j==1)  dp[i][j] = s[i][j]=='#';
            if(i>1)
            {
                if(s[i][j]=='#'&&s[i-1][j]=='#')    dp[i][j] = min(dp[i][j],dp[i-1][j]);
                else if(s[i][j]=='#')               dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                else                                dp[i][j] = min(dp[i][j],dp[i-1][j]);
            }
            if(j>1)
            {
                if(s[i][j]=='#'&&s[i][j-1]=='#')    dp[i][j] = min(dp[i][j],dp[i][j-1]);
                else if(s[i][j]=='#')               dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                else                                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
