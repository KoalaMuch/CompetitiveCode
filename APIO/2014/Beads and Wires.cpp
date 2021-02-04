#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[N][4];
vector< pair< int,int > > g[N];
void solve(int u,int p = -1)
{
    int sum01 = 0,mx = -2e9,mx0 = -2e9,mx1 = -2e9,mx2 = -2e9,mx02 = -2e9,mx3 = -2e9,mx4 = -2e9;
    for(auto &x:g[u])
    {
        if(x.first==p)    continue;
        solve(x.first,u);
        int cut = max(dp[x.first][0],dp[x.first][1]+x.second);
        sum01 += cut;
        mx = max(mx,dp[x.first][0]-cut+x.second);
        if(mx0!=-2e9)   mx02 = max(mx02,mx0+max(dp[x.first][0],dp[x.first][2])+x.second-cut);
        if(mx2!=-2e9)   mx02 = max(mx02,mx2+dp[x.first][0]+x.second-cut);
        mx0 = max(mx0,dp[x.first][0]+x.second-cut);
        mx1 = max(mx1,max(max(dp[x.first][0],dp[x.first][2]),dp[x.first][1]+x.second)-cut);
        mx2 = max(mx2,max(dp[x.first][0],dp[x.first][2])-cut+x.second);
        mx3 = max(mx3,dp[x.first][2]-cut+x.second);
        mx4 = max(mx4,dp[x.first][3]-cut+x.second);
    }
    dp[u][0] = sum01,dp[u][1] = sum01+mx,dp[u][2] = sum01+max(mx02,max(mx1,mx4)),dp[u][3] = sum01+mx3;
}
int main()
{
    int n,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<n;i++)    scanf("%d %d %d",&u,&v,&w),g[u].push_back({v,w}),g[v].push_back({u,w});
    solve(1);
    printf("%d\n",max(dp[1][0],dp[1][2]));
    return 0;
}
/*
11
4 10 2
1 2 21
1 3 13
6 7 1
7 9 5
2 4 3
2 5 8
1 6 55
6 8 34
11 1 1

8
1 3 49
1 7 52
1 2 38
2 4 25
2 6 21
4 8 2
4 5 5

7
1 2 4
1 3 5
2 4 15
2 5 13
3 6 11
3 7 8
*/
