#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int p[N];
int belong[N];
int sz[N];
vector< int > g[N];
vector< int > state[N];
int fin(int i)  {return p[i]==i ? i : p[i]=fin(p[i]);}
int main()
{
    int n,k,u,v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++)    scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    for(int i=1;i<=n;i++)   scanf("%d",&belong[i]),p[i] = i,sz[i] = 1;
    for(int i=1;i<=n;i++)
    {
        state[belong[i]].push_back(i);
        for(auto &x:g[i])
        {
            u = fin(i),v = fin(x);
            if(belong[u]==belong[v]&&u!=v)  sz[u]+=sz[v],p[v] = u;
        }
    }
    int ans = 0;
    for(int i=1;i<=k;i++)
    {
        if(state[i].size()==sz[fin(state[i][0])])
        {
            int cnt = 0;
            for(auto &x:state[i])
            {
                for(auto &y:g[x])
                {
                    cnt+=belong[y]!=i;
                }
            }
            if(cnt==1)  ++ans;
        }
    }
    printf("%d\n",(ans+1) >> 1);
    return 0;
}
/*
6 5
1 2 1 3 1 4 1 5 1 6
1 2 3 4 5 1
*/
