#include<bits/stdc++.h>
using namespace std;
const int N = 405;
int dp[N][N];
int pre[N][27];
char a[N];
char b[N];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %s %s",a+1,b+1);
        n = strlen(a+1); m = strlen(b+1);
        if(m>n) {printf("NO\n");continue;}
        for(int i=0;i<=n;i++)   for(int j=0;j<26;j++)   pre[i][j] = 1e9;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)   pre[i][j] = pre[i+1][j];
            pre[i][a[i+1]-'a'] = i+1;
        }
        int ch = 0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=i;j++)
            {
                for(int k=i;k<=m;k++)
                {
                    if(!j&&k==i)  continue;
                    dp[j][k] = 1e9;
                    if(j>0&&dp[j-1][k]<=n)   dp[j][k] = min(dp[j][k],pre[dp[j-1][k]][b[j]-'a']);
                    if(k>i&&dp[j][k-1]<=n)   dp[j][k] = min(dp[j][k],pre[dp[j][k-1]][b[k]-'a']);
                }
            }
            ch|=dp[i][m]<=n;
            for(int j=0;j<=i;j++)   for(int k=i;k<=m;k++) dp[j][k] = 0;
        }
        printf((ch) ? "YES\n" : "NO\n");
    }
    return 0;
}
