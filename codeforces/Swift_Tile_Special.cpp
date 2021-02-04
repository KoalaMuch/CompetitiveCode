#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main()
{
    //dp[i][j] =
    dp[0][0] = 1
    for(int i=1;i<=100;i++)
    {
        for(int j=0;j<=50;j++)
        {
            //case 1
            dp[i][j] += dp[i-1][j];
            //case 2
            if(i>1) dp[i][j] += dp[i-2][j];

            //case 4

            for(int k=i-3;k>=0;k-=2) //1,4
            {
                if(j>1) dp[i][j] += dp[k][j-2]*2;
            }
        }
    }
    int q,a,b;
    scanf("%d",&q);
    while(q--)
    {

    }
    return 0;
}
