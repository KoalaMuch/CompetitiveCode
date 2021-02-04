#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int dp[N][2][2];
//dp[i][0][0]  = end with a[i]&&value<=0
//dp[i][0][1]  = end with a[i]&&value>=0
//dp[i][1][0]  = end with b[i]&&value<=0
//dp[i][1][1]  = end with b[i]&&value>=0
int from[N][41];
int a[N];
int b[N];
vector< char > ans;
void check(int cur,int i,int j,int k,int l)
{
    int A,B,add,v;
    if(i==0)    A = a[cur-1];
    else        A = b[cur-1];
    if(k==0)    B = a[cur],add = -1;
    else        B = b[cur],add = 1;
    if(B<A) return ;
    if(l==0)
    {
        v = dp[cur-1][i][j]+add;
        if(v>=dp[cur][k][l]&&v<=0)  dp[cur][k][l] = v,from[cur][k][l] = {i,j};
    }
    else
    {
        v = dp[cur-1][i][j]+add;
        if(v<=dp[cur][k][l]&&v>=0)  dp[cur][k][l] = v,from[cur][k][l] = {i,j};
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    n<<=1;
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2;j++)    for(int k=0;k<2;k++)    from[i][j][k] = {-1,-1};
        dp[i][0][0] = dp[i][1][0] = -1e9;
        dp[i][0][1] = dp[i][1][1] = 1e9;
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    for(int m=0;m<2;m++)    check(i,j,k,l,m);
                }
            }
        }
    }
    pair< int,int > cur = {-1,-1};
    for(int i=0;i<2;i++)    for(int j=0;j<2;j++)    if(dp[n][i][j]==0)  cur = {i,j};
    if(cur.first==-1)   return puts("-1"),0;
    for(int i=n;i>=1;i--)
    {
        ans.push_back(cur.first+'A');
        cur = from[i][cur.first][cur.second];
    }
    reverse(ans.begin(),ans.end());
    for(auto &x:ans)    printf("%c",x);
    return 0;
}
/*
6
25 18 40 37 29 95 41 53 39 69 61 90
14 18 22 28 18 30 32 32 63 58 71 78

2
2 2 5 3
1 8 4 4
*/
