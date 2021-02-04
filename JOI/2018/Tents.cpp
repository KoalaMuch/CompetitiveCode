#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
const long long mod = 1e9+7;
long long dp[N][N];
long long pc[N][3];
int main()
{
    int n,m;
    pc[0][0] = 1;
    for(int i=1;i<=3000;i++)
        for(int j=0;j<=2;j++)
        {
            pc[i][j] = pc[i-1][j];
            if(j)   pc[i][j] = (pc[i][j]+pc[i-1][j-1])%mod;
        }
    for(int i=1;i<=3000;i++)
    {
        for(int j=1;j<=3000;j++)
        {
            dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
        }
    }
    scanf("%d %d",&n,&m);
    printf("%lld\n",dp[n][m]);
    return 0;
}
/*
1 1 4
1 2 9
1 3 15
1 4 22
2 1 9
2 2 52
2 3 153
2 4 342
3 1 15
3 2 153
3 3 875
3 4 3236
4 1 22
4 2 342
4 3 3236
4 4 19880
*/
