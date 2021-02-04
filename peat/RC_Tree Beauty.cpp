#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int dp[N];
int dp2[N];
int val[N];
int mark[N];
vector< int > g[N];
int ans1;
int ans2;
int u[N];
int v[N];
void solve(int u,int pa = -1,bool p2 = false)
{
    if(val[u]==2&&p2==true) return ;
    mark[u] = 1;
    if(val[u]==1)   dp[u] = 1;
    if(val[u]==2)   dp2[u] = 1,p2 = true;
    for(auto x:g[u])
    {
        if(pa==x)   continue;
        solve(x,u);
        if(val[u]==1)
        {
            ans1 = ans1 > dp[x]+dp[u] ? ans1 : dp[x]+dp[u];
            if(dp2[u])   ans2 = ans2>dp2[u]+dp[x] ? ans2 : dp2[u]+dp[x],dp2[u] = dp2[u]>dp2[x]+1 ? dp2[u] : dp2[x]+1;
            if(dp2[x])   ans2 = ans2>dp2[x]+dp[u] ? ans2 : dp2[x]+dp[u],dp2[u] = dp2[u]>dp2[x]+1 ? dp2[u] : dp2[x]+1;
            dp[u] = dp[u] > dp[x]+1 ? dp[u] : dp[x]+1;
        }
        else
        {
            ans2 = ans2>dp[u]+dp[x] ? dp[u]+ans2 : dp[u]+dp[x];
            dp2[u] = dp2[u] > dp[x]+1 ? dp2[u] : dp[x]+1;
        }
    }
}
void getans(int mn,int ch1,int ch2)
{
    double a = mn,b = !ch1 ? 1e9 : 1.0/ch1,c = !ch2 ? 1e9 : 2.0/ch2;
    if(a<=b&&a<=c)    printf("%d/1",mn);
    else if(b<=a&&b<=c) printf("%d/%d\n",1,ch1);
    else              printf("%d/%d\n",2,ch2);
}
int main()
{
    int n,mn = 1e9;
    bool ch;
    scanf("%d",&n);
    for(int i=1;i<n;i++)    scanf("%d %d",&u[i],&v[i]);
    for(int i=1;i<=n;i++)   scanf("%d",&val[i]),mn = min(mn,val[i]);
    for(int i=1;i<n;i++)    if(val[u[i]]<=2&&val[v[i]]<=2)    g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
    for(int i=1;i<=n;i++)
    {
        if(val[i]<=2&&!mark[i])   solve(i);
    }
    getans(mn,ans1,ans2);
    return 0;
}
