#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][2];
int pa[18][N];
int lvl[N];
vector< int > g[N];
void dfs(int u,int p)
{
    if(p!=0)    lvl[u] = lvl[p]+1,pa[0][u] = p;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        dfs(x,u);
        if(dp[x][0]+1>dp[u][0])         dp[u][1] = dp[u][0],dp[u][0] = dp[x][0]+1;
        else if(dp[x][0]+1>dp[u][1])    dp[u][1] = dp[x][0]+1;
    }
}
void reroot(int u,int p)
{
    if(p!=0)
    {
        if(dp[p][0]==dp[u][0]+1)
        {
            if(dp[p][1]+1>dp[u][0])         dp[u][1] = dp[u][0],dp[u][0] = dp[p][1]+1;
            else if(dp[p][1]+1>dp[u][1])    dp[u][1] = dp[p][1]+1;
        }
        else
        {
            if(dp[p][0]+1>dp[u][0])         dp[u][1] = dp[u][0],dp[u][0] = dp[p][0]+1;
            else if(dp[p][0]+1>dp[u][1])    dp[u][1] = dp[p][0]+1;
        }
    }
    for(auto &x:g[u])
    {
        if(x!=p)    reroot(x,u);
    }
}
int dis(int a,int b,int ret = 0)
{
    if(lvl[a]>lvl[b])   swap(a,b);
    for(int i=17;i>=0;i--)
    {
        if(pa[i][b]!=0&&lvl[pa[i][b]]>=lvl[a])   ret+=(1<<i),b = pa[i][b];
    }
    if(a==b)    return ret;
    for(int i=17;i>=0;i--)
    {
        if(pa[i][a]!=pa[i][b])   ret+=(1<<i)*2,a = pa[i][a],b = pa[i][b];
    }
    return ret+2;
}
int main()
{
    int q,n,da,db,a,b,u,v;
    scanf("%d",&q);
    while(q--)
    {
        bool found = false;
        scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
        db = min(db,da*2+1);
        for(int i=1;i<n;i++)    scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
        dfs(1,0);
        reroot(1,0);
        for(int i=1;i<=17;i++)
        {
            for(int j=1;j<=n;j++)
            {
                pa[i][j] = pa[i-1][pa[i-1][j]];
            }
        }
        for(int i=1;i<=n;i++)
        {
            int av = (dis(a,i)+(da-1))/da,bv = (dis(b,i)+(db-1))/db;
            if(bv+2<=av&&da*2<db&&dp[i][0]>=db) found = true;
        }
        printf( found ? "Bob\n" : "Alice\n");
        for(int i=1;i<=n;i++)   g[i].clear(),dp[i][0] = dp[i][1] = 0;
    }
    return 0;
}
/*
1
6 6 1 2 5
1 2
6 5
2 3
3 4
4 5
*/
