#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int sz[N];
int p[N];
int* where[4*N];
int val[4*N];
int cur;
int comp;
bool question[N];
int ans[N];
int fin(int i)  {return i==p[i] ? i : fin(p[i]);}
map< pair< int,int > ,int > mp;
vector< pair< int,int > > T[4*N];
void change(int& x,int y)
{
    where[cur] = &x;
    val[cur] = x;
    x=y;
    ++cur;
}
void rollback()
{
    cur--;
    (*where[cur]) = val[cur];
}
void Merge(int x,int y)
{
    x = fin(x),y = fin(y);
    if(x==y)    return ;
    --comp;
    if(sz[x]<sz[y]) swap(x,y);
    change(p[y],x);
    change(sz[x],sz[x]+sz[y]);
}
void add(int v,int l,int r,int L,int R,pair< int,int > val)
{
    if(L>=R)    return ;
    if(l==L&&r==R)  {T[v].push_back(val);return;}
    int m = (l+r) >> 1;
    add(v*2+1,l,m,L,min(R,m),val),add(v*2+2,m,r,max(L,m),R,val);
}
void dfs(int v,int l,int r)
{
    if(l==r)    return ;
    int memo = comp,state = cur;
    for(auto &x:T[v])   Merge(x.first,x.second);
    if(l==r-1)  ans[l] = comp;
    else
    {
        int m = (l+r) >> 1;
        dfs(v*2+1,l,m),dfs(v*2+2,m,r);
    }
    while(cur!=state)   rollback();
    comp = memo;
}
void init()
{
    for(int i=0;i<N;i++)    p[i] = i,sz[i] = 1;
}
int main()
{
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    int n,k;
    char opr;
    scanf("%d %d",&n,&k);
    comp = n;
    for(int i=0;i<k;i++)
    {
        scanf(" %c",&opr);
        if(opr=='?')    question[i] = true;
        else
        {
            int u,v;
            scanf("%d %d",&u,&v);
            --u,--v;
            if(u>v) swap(u,v);
            pair< int,int > pii = {u,v};
            if(opr=='-')    add(0,0,k,mp[pii],i,pii),mp.erase(pii);
            else            mp[pii] = i;
        }
    }
    for(auto &x:mp) add(0,0,k,x.second,k,x.first);
    init();
    dfs(0,0,k);
    for(int i=0;i<k;i++)    if(question[i]) printf("%d\n",ans[i]);
    return 0;
}
/*
5 11
?
+ 1 2
+ 2 3
+ 3 4
+ 4 5
+ 5 1
?
- 2 3
?
- 4 5
?
*/
