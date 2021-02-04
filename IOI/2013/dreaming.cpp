#include "dreaming.h"
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< pair< int,int > > g[N];
bool mark[N];
int ans;
int dp[N][2];
int all[N];
void dfs(int u,int p = -1)
{
    mark[u] = true;
    for(auto &x:g[u])
    {
        if(x.first==p)    continue;
        dfs(x.first,u);
        if(dp[x.first][0]+x.second>dp[u][0])        dp[u][1] = dp[u][0],dp[u][0] = dp[x.first][0]+x.second;
        else if(dp[x.first][0]+x.second>dp[u][1])   dp[u][1] = dp[x.first][0]+x.second;
    }
}
int reroot(int u,int p = -1)
{
    int mn = dp[u][0];
    for(auto &x:g[u])
    {
        if(x.first==p)  continue;
        int nowv = x.second+dp[u][0];
        if(x.second+dp[x.first][0]==dp[u][0])            nowv = dp[u][1]+x.second;
        if(nowv>dp[x.first][0])       dp[x.first][1] = dp[x.first][0],dp[x.first][0] = nowv;
        else if(nowv>dp[x.first][1])  dp[x.first][1] = nowv;
        mn = min(mn,reroot(x.first,u));
    }
    ans = max(ans,dp[u][0]+dp[u][1]);
    return mn;
}
int travelTime(int n, int m, int l, int a[], int b[], int t[])
{
    int cnt = 0;
    for(int i=0;i<m;i++)    g[a[i]].push_back({b[i],t[i]}),g[b[i]].push_back({a[i],t[i]});
    for(int i=0;i<n;i++)
    {
        if(!mark[i])
        {
            ++cnt;
            dfs(i);
            all[cnt] = reroot(i);
        }
    }
    sort(all+1,all+cnt+1);
    if(cnt>=2)    ans = max(ans,all[cnt]+all[cnt-1]+l);
    if(cnt>=3)    ans = max(ans,all[cnt-1]+all[cnt-2]+2*l);
    return ans;
}
/*
12 8 2
0 8 4
8 2 2
2 7 4
5 11 3
5 1 7
1 3 1
1 9 5
10 6 3
*/
