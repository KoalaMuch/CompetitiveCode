#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int par[N]; //parent of node i
int dep[N]; //depth of node i
int spi[N]; // next chain of no de i = heavy node of node i
int pos[N]; //position in segment tree of node i
int rot[N]; //root of chain
int sm[N*4]; //segment tree
char opr[10];
int v[N];
int cur;
int n;
pair< pair< int,int > ,int > edge[N];
vector< int > g[N];
int dfs(int u,int p = 0)
{
    dep[u] = dep[p]+1,par[u] = p;
    int sz = 1;
    pair< int,int > ret = {0,-1};
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        int z = dfs(x,u);
        sz+=z;
        if(z>ret.first)    ret = {z,x};
    }
    spi[u] = ret.second;
    return sz;
}
int decompose(int u,int h)
{
    rot[u] = h,pos[u] = ++cur;
    if(spi[u]!=-1)  decompose(spi[u],h);
    for(auto &x:g[u])
    {
        if(x!=par[u]&&x!=spi[u])    decompose(x,x);
    }
}
void build(int l = 1,int r = n,int now = 1)
{
    if(l==r)    {sm[now] = v[l];return;}
    int mid = (l+r) >> 1;
    build(l,mid,now<<1),build(mid+1,r,now<<1|1);
    sm[now] = max(sm[now<<1],sm[now<<1|1]);
}
int querytree(int ll,int rr,int l = 1,int r = n,int now = 1)
{
    if(l>rr||r<ll)  return 0;
    if(l>=ll&&r<=rr)    return sm[now];
    int mid = (l+r) >> 1;
    return max(querytree(ll,rr,l,mid,now<<1),querytree(ll,rr,mid+1,r,now<<1|1));
}
void updatetree(int idx,int val,int l = 1,int r = n,int now = 1)
{
    if(l>idx||r<idx)    return ;
    if(l==r)    {sm[now] = val;return;}
    int mid = (l+r) >> 1;
    if(idx<=mid)    updatetree(idx,val,l,mid,now<<1);
    else            updatetree(idx,val,mid+1,r,now<<1|1);
    sm[now] = max(sm[now<<1],sm[now<<1|1]);
}
int get_maxpath(int a,int b)
{
    int ret = 0;
    for(;rot[a]!=rot[b];b = par[rot[b]])
    {
        if(dep[rot[a]]>dep[rot[b]]) swap(a,b);
        ret = max(ret,querytree(pos[rot[b]],pos[b]));
    }
    if(a==b)    return ret;
    if(dep[a]>dep[b])   swap(a,b);
    ret = max(ret,querytree(pos[a]+1,pos[b]));
    return ret;
}
void init()
{
    dfs(1);
    decompose(1,1);
    for(int i=1;i<n;i++)
    {
        if(dep[edge[i].first.first]>dep[edge[i].first.second])  swap(edge[i].first.first,edge[i].first.second);
        v[pos[edge[i].first.second]] = edge[i].second;
    }
    build();
}
void Clear()
{
    for(int i=1;i<=n;i++)    g[i].clear();
    cur = 0;
}
int main()
{
    int T,u,v,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<n;i++)    scanf("%d %d %d",&u,&v,&w),edge[i] = {{u,v},w},g[u].push_back(v),g[v].push_back(u);
        init();
        while(1)
        {
            scanf(" %s",opr);
            if(opr[0]=='Q')
            {
                scanf("%d %d",&u,&v);
                printf("%d\n",get_maxpath(u,v));
            }
            else if(opr[0]=='C')
            {
                scanf("%d %d",&u,&w);
                updatetree(pos[edge[u].first.second],w);
            }
            else    break;
        }
        Clear();
    }
    return 0;
}
/*
2
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
QUERY 2 3
DONE
3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/
