#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
bool chk[2][N];
vector< long long > g[N];
void dfs(long long u,long long no,long long rnd)
{
    chk[rnd][u] = true;
    for(auto &x:g[u])
    {
        if(x==no||chk[rnd][x])   continue;
        dfs(x,no,rnd);
    }
}
int main()
{
    long long q,n,m,a,b,u,v,A,B;
    scanf("%lld",&q);
    while(q--)
    {
        A = B = 0;
        scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
        for(int i=1;i<=m;i++)   scanf("%lld %lld",&u,&v),g[u].push_back(v),g[v].push_back(u);
        dfs(a,b,0),dfs(b,a,1);
        for(long long i=1;i<=n;i++)
        {
            if(chk[0][i]&&!chk[1][i])   ++A;
            if(!chk[0][i]&&chk[1][i])   ++B;
            g[i].clear();
            chk[0][i] = chk[1][i] = false;
        }
        printf("%lld\n",A*B-A-B+1);
    }
    return 0;
}
