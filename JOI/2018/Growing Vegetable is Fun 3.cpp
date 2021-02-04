#include<bits/stdc++.h>
using namespace std;
const int N = 405;
char s[N];
int dp[N][N][3];
int get(char c)
{
    if(c=='R')  return 0;
    if(c=='G')  return 1;
    return 2;
}
void chkmn(int& x,int y){x = min(x,y);}
int main()
{
    int n;
    scanf("%d %s",&n,s+1);
    memset(dp,127,sizeof dp);
    dp[1][1][get(s[1])] = 0;
    for(int i=2;i<=n;i++)
    {
        int cur = get(s[i]);
        for(int j=1;j<=i;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==cur)
                {
                    if(j==1)
                    {
                        for(int l=0;l<3;l++)    if(l!=k)    chkmn(dp[i][j][k],dp[i-1][l][1]);
                    }
                    else    chkmn(dp[i][j][k],dp[i-1][j-1][k]);
                }
                else    chkmn(dp[i][j][k],dp[i-1][j+1][k]+j);
            }
        }
    }
    int ans = 1e9;
    printf("%d\n",dp[3][1][0]);
    for(int i=0;i<3;i++)    ans = min(ans,dp[n][1][i]);
    printf( ans==1e9 ? "-1\n" : "%d\n",ans);
    return 0;
}
/*
5
RRGYY
(2)

9
RGRGRYYYY
*/
