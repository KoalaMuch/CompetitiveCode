#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
const int M = 6e5+2;
int p[N];
int sz[N];
int ans[M];
int* where[M*50];
int val[M*50];
vector< pair< int,int > > T[M*4];
map< pair< int,int > ,int > mp;
int cur,cnt;
void init()
{
    for(int i=0;i<N;i++)    p[i] = i,sz[i] = 1;
}
void add(int v,int l,int r,int L,int R,pair< int,int > val)
{
    if(L>=R)    return;
    if(L==l&&R==r)
    {
        T[v].push_back(val);
    }
    else
    {
        int m = (l+r) >> 1;
        add(v*2+1,l,m,L,min(R,m),val),add(v*2+2,m,r,max(m,L),R,val);
    }
}
int get(int i)  {return i==p[i] ? i : get(p[i]);}
void rollback()
{
    --cur;
    (*where[cur]) = val[cur];
}
void change(int& x,int y)
{
    where[cur] = &x;
    val[cur] = x;
    x=y;
    cur++;
}
void Merge(int x,int y)
{
    x = get(x),y = get(y);
    if(x==y)    {cnt+=sz[x]%2;return;}
    if(sz[x]<sz[y]) swap(x,y);
    change(p[y],x);
    change(sz[x],sz[x]+sz[y]);
}
void dfs(int v,int l,int r)
{
    int memo = cnt,state = cur;
    for(auto &x:T[v])   Merge(x.first,x.second);
    if(l==r-1)
    {
        ans[l] = cnt;
    }
    else
    {
        int m = (l+r) >> 1;
        dfs(v*2+1,l,m),dfs(v*2+2,m,r);
    }
    while(cur!=state)   rollback();
    cnt = memo;
}
int main()
{
    init();
    int n,m,opr,u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&opr,&u,&v);
        --u,--v;
        if(u>v) swap(u,v);
        pair< int,int > pii = {u,v};
        if(mp.count(pii))   add(0,0,m,mp[pii],i,pii),mp.erase(pii);
        else                mp[pii] = i;
    }
    for(auto &x:mp) add(0,0,m,x.second,m,x.first);
    dfs(0,0,m);
    for(int i=0;i<m;i++)    printf( (ans[i]) ? "no\n" : "yes\n");
    return 0;
}
/*
5 8
1 1 5
1 4 3
1 3 2
1 1 4
1 5 2
0 4 3
0 2 5
1 5 4
*/
