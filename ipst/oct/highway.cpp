#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 2e5+5;
pair< int,int > opr[M];
int mark[N];
vector< int > g[N];
vector< int > rg[N];
bool s[N];
bool e[N];
bool ans[M];
queue< int > q;
void dfs1(int u)
{
    q.push(u);
    while(!q.empty())
    {
        int nowi = q.front();   q.pop();
        for(auto &x:g[nowi])    if(!s[x]&&!mark[x]) s[x] = 1,q.push(x);
    }
}
void dfs2(int u)
{
    q.push(u);
    while(!q.empty())
    {
        int nowi = q.front();   q.pop();
        for(auto &x:rg[nowi])    if(!e[x]&&!mark[x]) e[x] = 1,q.push(x);
    }
}
int main()
{
    int n,m,q,u,v;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++)   scanf("%d %d",&u,&v),g[u].push_back(v),rg[v].push_back(u);
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d",&opr[i].first,&opr[i].second);
        mark[opr[i].second] |= opr[i].first==1;
    }
    s[1] = 1,e[n] = 1;
    dfs1(1),dfs2(n);
    for(int i=q;i>=1;i--)
    {
        if(opr[i].first==1)
        {
            int ch = 0;
            mark[opr[i].second] = 0;
            for(auto &x:rg[opr[i].second])  ch|=s[x]==true;
            if(ch)  s[opr[i].second] = 1,dfs1(opr[i].second),ch = 0;
            for(auto &x:g[opr[i].second])   ch|=e[x]==true;
            if(ch)  e[opr[i].second] = 1,dfs2(opr[i].second);
        }
        else    ans[i] = s[opr[i].second]==true&&e[opr[i].second]==true;
    }
    for(int i=1;i<=q;i++)   if(opr[i].first==2) printf("%d\n",ans[i]);
    return 0;
}
/*
5 6 8
1 2
2 3
2 4
4 3
1 3
3 5
2 4
1 2
2 4
2 3
2 5
1 3
2 4
2 3
*/
