#include<bits/stdc++.h>
using namespace std;
const int N = 405;
char s[N];
int a[N];
int dp[N][N][3][3];
int main()
{
    int n;
    scanf("%d %s",&n,s+1);
    for(int i=1;i<=n;i++)   for(int j=i;j<=n;j++) for(int k=0;k<3;k++) for(int l=0;l<3;l++) dp[i][j][k][l] = 1e9;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='G')   a[i]=1;
        else if(s[i]=='Y')  a[i]=2;
        dp[i][i][a[i]][a[i]] = 0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=1,j=l;j<=n;i++,j++)
        {
            for(int k=i;k<j;k++)
            {
                for(int ii=0;ii<3;ii++)
                {
                    for(int jj=0;jj<3;jj++)
                    {
                        for(int kk=0;kk<3;kk++)
                        {
                            for(int ll=0;ll<3;ll++)
                            {
                                if(jj!=kk)  dp[i][j][ii][ll] = min(dp[i][j][ii][ll],dp[i][k][ii][jj]+dp[k+1][j][kk][ll]);
                            }
                        }
                    }
                }

//                for(int jj=0;jj<3;jj++)
//                {
//                    for(int kk=0;kk<3;kk++)
//                    {
//                        printf("%d %d %d %d %d\n",i,j,jj,kk,dp[i][j][jj][kk]);
//                    }
//                }
            }
            for(int ii=0;ii<3;ii++) for(int jj=0;jj<3;jj++)
                if(a[i]!=jj&&dp[i+1][j][ii][jj]!=1e9)    dp[i][j][ii][a[i]] = min(dp[i][j][ii][a[i]],l-1);
            for(int ii=0;ii<3;ii++) for(int jj=0;jj<3;jj++)
                if(a[j]!=ii&&dp[i][j-1][ii][jj]!=1e9)    dp[i][j][a[j]][jj] = min(dp[i][j][a[j]][jj],l-1);
        }
    }
    printf("%d\n",dp[5][8][1][2]);
    int mn = 1e9;
    for(int i=0;i<3;i++)    for(int j=0;j<3;j++)    mn = min(mn,dp[1][n][i][j]);
    printf(mn==1e9 ? "-1\n" : "%d\n",mn);
    return 0;
}
/*
20
YYGYYYGGGGRGYYGRGRYG
*/
