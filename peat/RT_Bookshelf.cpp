#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int pos[N*N];
int seq[N*N];
int lis[N];
int cnt[N];
int a[N][N];
int b[N][N];
int low[N];
int id[N];
int edge[N][N];
int t;
stack< int > st;
vector< int > g[N];
int sz;
int cmp;
bool onstack[N];
void scc(int u)
{
    ++sz;
    low[u] = id[u] = ++t;
    st.push(u),onstack[u] = true;
    for(auto &x:g[u])
    {
        if(!id[x])  scc(x),low[u] = min(low[u],low[x]);
        else if(onstack[x]) low[u] = min(low[u],id[x]);
    }
    if(low[u]==id[u])
    {
        ++cmp;
        while(st.top()!=u)  onstack[st.top()] = false,st.pop();
        st.pop();
        onstack[u] = false;
    }
}
int main()
{
    int n,m,gap = 0,ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])     pos[a[i][j]] = i,seq[a[i][j]] = ++cnt[i];
            else            ++gap;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int M = 0,all = 0,now = 0;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&b[i][j]);
            if(pos[b[i][j]]==i)
            {
                ++now;
                int idx = upper_bound(lis,lis+M,seq[b[i][j]])-lis;
                if(idx==M)  ++M;
                lis[idx] = seq[b[i][j]];
            }
            if(b[i][j])    ++all;
        }
        if(now==m&&M!=m)    ++ans;
        if(all==m)
        {
            for(int j=1;j<=m;j++)   if(pos[b[i][j]]!=i&&!edge[i][pos[b[i][j]]]) g[i].push_back(pos[b[i][j]]),edge[i][pos[b[i][j]]] = 1;
        }
        if(!gap&&M!=m)  return printf("-1\n"),0;
        ans+=cnt[i]-M;
    }
    for(int i=1;i<=n;i++)
    {
        if(low[i])  continue;
        cmp = sz = 0,scc(i);
        if(cmp==1&&sz!=1)   ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
/*
2 4 1 0 2 0 3 5 4 0 2 1 0 0 3 0 4 5

3 3
1 2 3
4 5 6
7 8 0

4 2 3
6 5 1
0 7 8
(4)
*/
