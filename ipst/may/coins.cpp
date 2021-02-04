#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector< long long > dp[N];
vector< long long > tmp[N];
vector< long long > g[N];
long long a[N];
long long b[N];
long long qs[N];
long long cal(long long a,long long b,long long r)
{
    return min(abs(a-b),r-abs(a-b));
}
int main()
{
    long long n,pos = 0,r,mx = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)    scanf("%lld",&a[i]),mx = max(mx,a[i]);
    for(long long i=1;i<=n;i++)    scanf("%lld",&b[i]);
    for(long long i=1;i<=n;i++)    qs[i]+=qs[i-1]+b[i],g[a[i]].push_back(qs[i]);
    r = qs[n];
    for(long long i=1;i<=mx;i++)
    {
        if(i==1)
        {
            long long sz = g[i].size();
            for(long long j=0;j<sz;j++)
            {
                dp[i].push_back(1e18);
                if(sz==1)      {dp[i][j] = 0;continue;}
                else if(sz==2) dp[i][j] = min(cal(g[i][0],g[i][1],r),cal(g[i][0],g[i][1],r));
                else           dp[i][j] = r-max(abs(g[i][j]-g[i][(j-1+sz)%sz]),abs(g[i][j]-g[i][(j+sz+1)%sz]));
            }
        }
        else
        {
            long long cur = 0,sz = g[i].size(),bf = g[i-1].size();
            long long mn = 1e18;
            for(long long j=0;j<sz;j++)
            {
                tmp[i].push_back(1e18);
                if(j!=0)    mn+=g[i][j]-g[i][j-1];
                while(cur<bf&&g[i-1][cur]<=g[i][j]) mn = min(mn,dp[i-1][cur]+g[i][j]-g[i-1][cur]),++cur;
                tmp[i][j] = min(tmp[i][j],mn);
            }
            cur = bf-1,mn = 1e18;
            for(long long j=sz-1;j>=0;j--)
            {
                if(j!=sz-1)    mn+=g[i][j+1]-g[i][j];
                while(cur>=0&&g[i-1][cur]>=g[i][j]) mn = min(mn,dp[i-1][cur]+g[i-1][cur]-g[i][j]),--cur;
                tmp[i][j] = min(tmp[i][j],mn);
            }
            cur = 0,mn = 1e18;
            for(long long j=0;j<sz;j++)
            {
                if(j!=0)    mn-=g[i][j]-g[i][j-1];
                while(cur<bf&&g[i-1][cur]<=g[i][j]) mn = min(mn,dp[i-1][cur]+r-g[i][j]+g[i-1][cur]),++cur;
                tmp[i][j] = min(tmp[i][j],mn);
            }
            cur = bf-1,mn = 1e18;
            for(long long j=sz-1;j>=0;j--)
            {
                if(j!=sz-1)    mn-=g[i][j+1]-g[i][j];
                while(cur>=0&&g[i-1][cur]>=g[i][j]) mn = min(mn,dp[i-1][cur]+r-g[i-1][cur]+g[i][j]),--cur;
                tmp[i][j] = min(tmp[i][j],mn);
            }
            for(long long j=0;j<sz;j++)
            {
                dp[i].push_back(1e18);
                if(sz==1)  dp[i][j] = tmp[i][j];
                else if(sz==2)  dp[i][j] = min(tmp[i][(j-1+sz)%sz]+cal(g[i][j],g[i][(j-1+sz)%sz],r),tmp[i][(j+1+sz)%sz]+cal(g[i][j],g[i][(j+1+sz)%sz],r));
                else
                {
                    dp[i][j] = min(dp[i][j],tmp[i][(j-1+sz)%sz]+r-abs(g[i][j]-g[i][(j-1+sz)%sz]));
                    dp[i][j] = min(dp[i][j],tmp[i][(j+1+sz)%sz]+r-abs(g[i][j]-g[i][(j+1+sz)%sz]));
                }

            }
        }
    }
    long long mn = 1e18;
    for(auto &x : dp[mx])    mn = min(mn,x);
    printf("%lld\n",mn);
    return 0;
}
/*
5
3 2 1 1 2
1 1 1 1 1

5
1 1 1 1 1
2 2 3 4 5


*/
