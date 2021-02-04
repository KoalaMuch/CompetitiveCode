#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int lv[N];
int dp[18][N];
vector< int > g[N];
int mn[3];
void dfs(int u,int p  = 0)
{
    lv[u] = lv[p]+1,dp[0][u] = p;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        dfs(x,u);
    }
}
int query(int a,int b,int ret = 0)
{
    if(lv[a]>lv[b]) swap(a,b);
    for(int i=17;i>=0;i--)
    {
        if(lv[dp[i][b]]>=lv[a]) ret+=(1<<i),b = dp[i][b];
    }
    if(a==b)    return ret;
    for(int i=17;i>=0;i--)
    {
        if(dp[i][a]!=dp[i][b])  ret+=(1<<i)<<1,a=dp[i][a],b=dp[i][b];
    }
    return ret+2;
}
int main()
{
    int n,u,v,a,b,k,q,x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++)    scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    dfs(1);
    for(int i=1;i<=17;i++)  for(int j=1;j<=n;j++)   dp[i][j] = dp[i-1][dp[i-1][j]];
    scanf("%d",&q);
    while(q--)
    {
        mn[0] = mn[1] = 2e9;
        scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
        int p1 = query(a,x)+1+query(y,b);
        int p2 = query(a,x)+query(x,y)+query(y,b);
        int p3 = query(b,x)+1+query(y,a);
        int p4 = query(b,x)+query(x,y)+query(y,a);
        int p5 = query(a,b);
        mn[p1%2] = min(mn[p1%2],p1);
        mn[p2%2] = min(mn[p2%2],p2);
        mn[p3%2] = min(mn[p3%2],p3);
        mn[p4%2] = min(mn[p4%2],p4);
        mn[p5%2] = min(mn[p5%2],p5);
        printf( mn[k%2] <= k  ? "YES\n" : "NO\n");
    }
    return 0;
}
/*
4
2 1
3 2
4 3
1
1 4 1 2 1000000000

5
1 2 2 3 3 4 4 5
1
1 1 1 1 1
*/
