#include<bits/stdc++.h>
using namespace std;
int dp[12][12][12];
int main()
{
    dp[1][1][1] = 1;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            for(int k=1;k<=10;k++)
            {
                for(int l=1;l<=10;l++)
                {
                    for(int m=1;m<=10;m++)
                    {
                        for(int x=1;x<=10;x++)
                        {
                            dp[i+l][max(j,m)][max(k,x+1)]|=(dp[i][j][k]&dp[l][m][x]);
                            dp[i+l][j+m][max(k+1,x)]|=(dp[i][j][k]&dp[l][m][x]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",dp[2][2][1]);
    return 0;
}
/*
1 1 1
2 1 2
2 2 1
*/
