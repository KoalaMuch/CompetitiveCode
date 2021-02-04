#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int a[5][5];
int dp[5][5];
int res()
{
    dp[0][1] = a[1][1];
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            dp[i][j] = max(dp[i-1][j]&a[i][j],dp[i][j-1]&a[i][j]);
        }
    }
    return dp[3][3];
}
int main()
{
    int k,b;
    scanf("%d",&k);
    for(int i=0;i<=18;i++)
    {
        if((1<<i)>k)    {b=1<<i;break;}
    }
    a[1][1] = a[3][2] = k|b;
    a[1][2] = a[1][3] = a[2][2] = a[2][3] = b;
    a[2][1] = a[3][1] = a[3][3] = k;
//    printf("%d\n",res());
    printf("3 3\n");
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
