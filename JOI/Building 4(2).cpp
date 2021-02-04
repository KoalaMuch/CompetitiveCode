#include<bits/stdc++.h>
using namespace std;
const int N = 4005;
bool dp[N][N][2];
pair< int,int > from[N][N][2];
vector< char > ans;
int a[N];
int b[N];
int main()
{
    int n;
    scanf("%d",&n);
    n<<=1;
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
    dp[0][2000][0] = dp[0][2000][1] = true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=4000;j++)
        {
            if(a[i]>=a[i-1]&&j+1<=4000&&dp[i-1][j+1][0])    dp[i][j][0] = true,from[i][j][0] = {j+1,0};
            if(a[i]>=b[i-1]&&j+1<=4000&&dp[i-1][j+1][1])    dp[i][j][0] = true,from[i][j][0] = {j+1,1};
            if(b[i]>=a[i-1]&&j-1>=0&&dp[i-1][j-1][0])     dp[i][j][1] = true,from[i][j][1] = {j-1,0};
            if(b[i]>=b[i-1]&&j-1>=0&&dp[i-1][j-1][1])     dp[i][j][1] = true,from[i][j][1] = {j-1,1};
        }
    }
    pair< int,int > cur = {-1,-1};
    if(dp[n][2000][0]==true)  cur = {2000,0};
    if(dp[n][2000][1]==true)  cur = {2000,1};
    if(cur.first==-1)   return puts("-1"),0;
    for(int i=n;i>=1;i--)
    {
        ans.push_back(cur.second+'A');
        cur = from[i][cur.first][cur.second];
    }
    reverse(ans.begin(),ans.end());
    for(auto &x:ans)    printf("%c",x);
    return 0;
}
/*

2
2 2 5 3
1 8 4 4

6
25 18 40 37 29 95 41 53 39 69 61 90
14 18 22 28 18 30 32 32 63 58 71 78
*/

