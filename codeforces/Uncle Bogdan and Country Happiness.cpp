#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< int > g[N];
int h[N];
int v[N];
void dfs1(int u,int p)
{
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        dfs1(x,u);
        v[u]+=v[x];
    }
}
int dfs2(int u,int p,int good,int bad)
{
    if(good<0||bad<0)   return 0;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        if((h[x]+v[x])%2)   return 0;
        int wantgood = (h[x]+v[x])/2;
        int wantbad = v[x]-wantgood;
        if(wantbad<0||wantgood>good||wantgood<0)   return 0;
        good-=wantgood;
        if(bad<wantbad) good-=(wantbad-bad),bad=0;
        else            bad-=wantbad;
        if(bad<0||good<0) return 0;
        int get = dfs2(x,u,wantgood,wantbad);
        if(!get)    return 0;
    }
    return 1;
}
int main()
{
    int q,n,a,b,m;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)   scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)   scanf("%d",&h[i]);
        for(int i=1;i<n;i++)    scanf("%d %d",&a,&b),g[a].push_back(b),g[b].push_back(a);
        dfs1(1,0);
        if((h[1]+v[1])%2)   printf("NO\n");
        else                printf(dfs2(1,0,(h[1]+v[1])/2,m-(h[1]+v[1])/2) ? "YES\n" : "NO\n");
        for(int i=1;i<=n;i++)   h[i] = v[i] = 0,g[i].clear();
    }
    return 0;
}
