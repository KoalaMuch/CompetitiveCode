#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< pair< int,int >  > g[N];
int p[N];
int lca[17][N];
int lvl[N];
int w[17][N];
struct A
{
    int u,v,w;
    bool operator<(const A&o)const
    {
        return w<o.w;
    }
};
A edge[3*N];
int POW(int a)
{
    int P = 2,ret = 1;
    for(int j=0;j<=29;j++,P = P*P%33331)    if((1<<j)&a) ret = ret*P%33331;
    return ret;
}
int fin(int i)  {return i==p[i] ? i : p[i] = fin(p[i]);}
void dfs(int u,int pa = 0,int lst = 0,int dep = 1)
{
    lca[0][u] = pa,w[0][u] = POW(lst),lvl[u] = dep;
    for(auto &x:g[u])  if(x.first!=pa)    dfs(x.first,u,x.second,dep+1);
}
int query(int u,int v)
{
    int ret = 0;
    if(lvl[u]>lvl[v])   swap(u,v);
    for(int i=16;i>=0;i--)
    {
        if(lvl[lca[i][v]]>=lvl[u])  ret = (ret+w[i][v])%33331,v = lca[i][v];
    }
    if(u==v)    return ret;
    for(int i=16;i>=0;i--)
    {
        if(lca[i][u]!=lca[i][v])    ret = (ret+w[i][v]+w[i][u])%33331,u = lca[i][u],v = lca[i][v];
    }
    return (ret+w[0][u]+w[0][v])%33331;
}
int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)       p[i] = i;
    for(int i=1;i<=m;i++)   scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge+1,edge+m+1);
    for(int i=1;i<=m;i++)
    {
        int ru = fin(edge[i].u),rv = fin(edge[i].v);
        if(ru!=rv)  p[ru] = rv,g[edge[i].u].push_back({edge[i].v,edge[i].w}),g[edge[i].v].push_back({edge[i].u,edge[i].w});
    }
    dfs(1);
    for(int i=1;i<=16;i++)
        for(int j=1;j<=n;j++)
            lca[i][j] = lca[i-1][lca[i-1][j]],w[i][j] = (w[i-1][j]+w[i-1][lca[i-1][j]])%33331;
    while(q--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        printf("%d\n",query(u,v));
    }
    return 0;
}
/*
4 5 3
1 2 3
3 1 0
3 2 4
2 4 5
4 3 2
2 3
3 4
3 3
*/
