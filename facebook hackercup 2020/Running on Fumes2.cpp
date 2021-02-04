#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct A
{
    int u,w,lft;
    bool operator<(const A&o)const
    {
        if(w!=o.w)  return w>o.w;
        return lft<o.lft;
    }
};
priority_queue< A > pq;
vector< int > g[N];
int lca[21][N];
int lvl[N];
long long dp[N];
int getdist(int a,int b,int ans = 0)
{
    if(lvl[a]>lvl[b])   swap(a,b);
    for(int i=20;i>=0;i--)  if(lvl[lca[i][a]]>=lvl[b])  ans+=1<<i,a = lca[i][a];
    if(a==b)    return ans;
    for(int i=20;i>=0;i--)  if(lca[i][a]!=lca[i][b])    a = lca[i][a],b = lca[i][b],ans+=(1<<i)*2;
    return 2+ans;
}
void dfs(int u,int p = 0)
{
    lvl[u] = lvl[p]+1;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        dfs(x,u);
    }
}
int main()
{
    int T,n,m,a,b;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        scanf("%d %d %d %d",&n,&m,&a,&b);
        for(int i=1;i<=n;i++)   scanf("%d",&lca[0][i]);
        for(int i=2;i<=n;i++)   g[lca[0][i]].push_back(i),g[i].push_back(lca[0][i]);
        dfs(1);
        for(int i=1;i<=17;i++)
        {
            for(int j=1;j<=n;j++)
            {
                lca[i][j] = lca[i-1][lca[i-1][j]];
            }
        }
        for(int i=1;i<=n;i++)   dp[i] = 1e18;
        dp[a] = 0;
        pq.push({a,0,m});
        while(!pq.empty())
        {
            int nowu = pq.top().u,noww = pq.top().w,nowlft = pq.top().lft;pq.pop();
            if(!nowlft) continue;
            for(auto &x:g[u])
            {
                if(noww<dp[x])
            }
        }
    }
    return 0;
}
