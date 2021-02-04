#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int cnt[27];
int p[N];
vector< int > g[N];
bool visit[N];
char s[N];
int fin(int i)
{
    if(i==p[i]) return i;
    return p[i] = fin(p[i]);
}
int main()
{
    int T,n,k;
    scanf("%d",&T);
    while(T--)
    {
        int ans = 0;
        scanf("%d %d %s",&n,&k,s+1);
        for(int i=1;i<=n;i++)   p[i] = i;
        for(int i=1;i<=n;i++)
        {
            int u = fin(i),v = fin(i+k);
            if(u!=v&&i+k<=n)    p[u] = v;
            u = fin(i),v = fin(n-i+1);
            if(u!=v)    p[u] = v;
        }
        for(int i=1;i<=n;i++)   g[fin(i)].push_back(i);
        for(int i=1;i<=n;i++)
        {
            int now = fin(i);
            if(!visit[now])
            {
                memset(cnt,0,sizeof cnt);
                visit[now] = true;
                int mx = 0;
                for(auto &x:g[now])
                {
                    ++cnt[s[x]-'a'];
                    mx = max(mx,cnt[s[x]-'a']);
                }
                ans+=(int)g[now].size()-mx;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)   g[i].clear();
        for(int i=1;i<=n;i++)   visit[i] = false;
    }
    return 0;
}
