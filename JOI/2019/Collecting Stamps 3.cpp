#include<bits/stdc++.h>
using namespace std;
const int N = 205;
int dp[N][N*2][N*2][2];
//dp[i][j][k][0] = collect i stamp from j th -> k th : 0 = at j 1 = at k
int a[N*2];
int t[N*2];
int L;
int cal(int i,int j)
{
    if(i>j) swap(i,j);
    return min(j-i,i+L-j);
}
int main()
{
    memset(dp,127,sizeof dp);
    int n,ans = 0;
    scanf("%d %d",&n,&L);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),a[i+n+1] = a[i];
    for(int i=1;i<=n;i++)   scanf("%d",&t[i]),t[i+n+1] = t[i];
    dp[0][n+1][n+1][0] = dp[0][n+1][n+1][1] = 0;
    for(int i=0;i<=n;i++)
    {
        for(int l=0;l<=n;l++)
        {
            for(int j=n+1-l,k=n+1;j<=n+1;j++,k++)
            {
                if(dp[i][j][k][0]<=1e9)
                {
                    ans = i;
                    if(l!=n)
                    {
                        if(j-1!=0)
                        {
                            int v = dp[i][j][k][0]+cal(a[j-1],a[j]);
                            dp[i][j-1][k][0] = min(dp[i][j-1][k][0],v);
                            if(v<=t[j-1])   dp[i+1][j-1][k][0] = min(dp[i+1][j-1][k][0],v);
                        }
                        if(k+1<=2*n+1)
                        {
                            int v = dp[i][j][k][0]+cal(a[j],a[k+1]);
                            dp[i][j][k+1][1] = min(dp[i][j][k+1][1],v);
                            if(v<=t[k+1])   dp[i+1][j][k+1][1] = min(dp[i+1][j][k+1][1],v);
                        }
                    }
                }
                if(dp[i][j][k][1]<=1e9)
                {
//                    if(i==3&&j==5&&k==9)    printf("---");
                    ans = i;
                    if(l!=n)
                    {
                        if(j-1!=0)
                        {
                            int v = dp[i][j][k][1]+cal(a[j-1],a[k]);
                            dp[i][j-1][k][0] = min(dp[i][j-1][k][0],v);
                            if(v<=t[j-1])   dp[i+1][j-1][k][0] = min(dp[i+1][j-1][k][0],v);
                        }
                        if(k+1<=2*n+1)
                        {
                            int v = dp[i][j][k][1]+cal(a[k],a[k+1]);
                            dp[i][j][k+1][1] = min(dp[i][j][k+1][1],v);
                            if(v<=t[k+1])   dp[i+1][j][k+1][1] = min(dp[i+1][j][k+1][1],v);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
6 25
3 4 7 17 21 23
11 7 17 10 8 10
(4)

5 20
4 5 8 13 17
18 23 15 7 10
(5)

10 87
9 23 33 38 42 44 45 62 67 78
15 91 7 27 31 53 12 91 89 46
(5)

4 19
3 7 12 14
2 0 5 4
(0)
*/
