#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int ans[N];
vector< pair< int,int > > g[N];
int main()
{
    int n,cnt = 0,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++)    scanf("%d %d",&u,&v),g[u].push_back({v,i}),g[v].push_back({u,i});
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()>=3)
        {
            ans[g[i][0].second] = ++cnt;
            ans[g[i][1].second] = ++cnt;
            ans[g[i][2].second] = ++cnt;
            break;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(!ans[i]) ans[i]=++cnt;
        printf("%d\n",ans[i]-1);
    }
    return 0;
}
