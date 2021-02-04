#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< int > g[N];
queue< int > num[4];
queue< int > lft;
queue< pair< int,int > > q;
int ans[N];
int dp[N][5];
int mk[N];
void get_dp(int u,int p = 0)
{
    dp[u][0] = 1;
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        get_dp(x,u);
        dp[u][1]+=dp[x][0];
        dp[u][2]+=dp[x][1];
        dp[u][3]+=dp[x][2];
    }
}
void reroot(int u,int p = 0)
{
    if(p)
    {
        int pl[4];
        for(int i=0;i<3;i++)
        {
            pl[i] = dp[p][i];
            if(i)   pl[i]-=dp[u][i-1];
        }
        for(int i=0;i<3;i++)    dp[u][i+1]+=pl[i];
    }
    for(auto &x:g[u])
    {
        if(x==p)    continue;
        reroot(x,u);
    }
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++)   scanf("%d %d",&u,&v),g[u].push_back(v),g[v].push_back(u);
    for(int i=1;i<=n;i++)   num[i%3].push(i);
    get_dp(1);
    reroot(1);
    q.push({1,0});
    mk[1] = 1;
    while(!q.empty())
    {
        int u = q.front().first,w = q.front().second; q.pop();
        if(dp[u][3])
        {
            if(!num[w+1].empty())      ans[u] = num[w+1].front(),num[w+1].pop();
            else if(!num[0].empty())   ans[u] = num[0].front(),num[0].pop();
            else                       return puts("-1"),0;
        }
        for(auto &x:g[u])
        {
            if(mk[x])   continue;
            mk[x] = 1;
            q.push({x,w^1});
        }
    }
    for(int i=0;i<3;i++)
    {
        while(!num[i].empty())
        {
            lft.push(num[i].front());
            num[i].pop();
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!ans[i])     ans[i] = lft.front(),lft.pop();
        printf("%d ",ans[i]);
    }

    return 0;
}
