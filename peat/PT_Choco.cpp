#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N][N];
int main()
{
    int q,a,b;
    for(int i=0;i<=33;i++)
    {
        for(int j=0;j<=33;j++)
        {
            if(i==0&&j==0)  continue;
            for(int k=500;k>=i;k--)
            {
                for(int l=500;l>=j;l--)
                {
                    dp[k][l] = max(dp[k][l],dp[k-i][l-j]+1);
                }
            }
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",dp[a][b]);
    }
    return 0;
}
