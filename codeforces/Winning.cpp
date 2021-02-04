#include<bits/stdc++.h>
using namespace std;
const int N = 27;
bool dp[N][N][N];
// dp[i][j][k] = i day(s) sum = j always has sum = k as suffix
int main()
{
    int T,n,m,p;
    scanf("%d",&T);
    dp[0][0][0] = 1;
    for(int i=1;i<=25;i++)
    {
        for(int j=i;j<=25;j++)
        {
            for(int k=1;k<=j;k++)
            {
                dp[i][j][k] true;
                for(int l=1;l<=min(j-i+1,k);l++)
                {
                    dp[i][j][k] &= dp[i-1][j-l][k-l];
                }
            }
        }
    }
    while(1)
    {
        scanf("%d",&n);
        if(!n)  break;
        scanf("%d %d",&m,&p);
        for(int)
        printf(dp[m][n][p][0] ? "yes\n" : "no\n");
    }
    return 0;
}
