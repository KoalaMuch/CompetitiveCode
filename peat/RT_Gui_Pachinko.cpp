#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int seq[N];
long long qs[N];
int cnt;
vector< int > g[N];
int max_sub[N];
bool cmp(int a,int b)
{
    return max_sub[a]<max_sub[b];
}
void dfs1(int u,int pa = 0)
{
    max_sub[u] = u;
    for(auto &x:g[u])
    {
        dfs1(x,u);
        max_sub[u] = max(max_sub[u],max_sub[x]);
    }
}
void dfs2(int u,int pa = 0)
{
    sort(g[u].begin(),g[u].end(),cmp);
    for(auto &x:g[u])   dfs2(x,u);
    seq[++cnt] = u;
}
int main()
{
    int n,m,root;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int pa;
        scanf("%d",&pa);
        if(!pa) root = i;
        else    g[pa].push_back(i);
    }
    dfs1(root);
    dfs2(root);
    for(int i=1;i<=n;i++)   qs[i]+=qs[i-1]+seq[i];
    int cur = 0;
    for(int i=1;i<=m;i++)
    {
        int cmd,x;
        scanf("%d",&cmd);
        if(cmd==1)      scanf("%d",&x),cur+=x,printf("%d\n",seq[cur]);
        else if(cmd==2) scanf("%d",&x),cur-=x;
        else            printf("%lld\n",qs[cur]);
    }
    return 0;
}
