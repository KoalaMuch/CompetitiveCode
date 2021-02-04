#include<bits/stdc++.h>
using namespace std;
const int N = 1505;
long long dp11[N][N];
long long dp1c[N][N];
long long dpr1[N][N];
long long dprc[N][N];
long long dp1[N][N];
long long dp2[N][N];
long long v[N][N];
long long vv[N][N];
long long solve(long long n,long long m)
{
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            dp11[i][j] = 1e12;
            if(i==1&&j==1)  dp11[i][j] = 0;
            if(i>1) dp11[i][j] = min(dp11[i][j],dp11[i-1][j]);
            if(j>1) dp11[i][j] = min(dp11[i][j],dp11[i][j-1]);
            dp11[i][j]+=v[i][j];
        }
        for(long long j=m;j>=1;j--)
        {
            dp1c[i][j] = 1e12;
            if(i==1&&j==m)  dp1c[i][j] = 0;
            if(i>1) dp1c[i][j] = min(dp1c[i][j],dp1c[i-1][j]);
            if(j<m) dp1c[i][j] = min(dp1c[i][j],dp1c[i][j+1]);
            dp1c[i][j]+=v[i][j];
        }
        for(long long j=1;j<=m;j++)
        {
            dp1[i][j] = dp11[i][j]+dp1c[i][j]-v[i][j];
            if(i>1) dp1[i][j] = min(dp1[i][j],dp1[i-1][j]+v[i][j]);
        }
    }
    for(long long i=n;i>=1;i--)
    {
         for(long long j=1;j<=m;j++)
        {
            dpr1[i][j] = 1e12;
            if(i==n&&j==1)  dpr1[i][j] = 0;
            if(i<n) dpr1[i][j] = min(dpr1[i][j],dpr1[i+1][j]);
            if(j>1) dpr1[i][j] = min(dpr1[i][j],dpr1[i][j-1]);
            dpr1[i][j]+=v[i][j];
        }
        for(long long j=m;j>=1;j--)
        {
            dprc[i][j] = 1e12;
            if(i==n&&j==m)  dprc[i][j] = 0;
            if(i<n) dprc[i][j] = min(dprc[i][j],dprc[i+1][j]);
            if(j<m) dprc[i][j] = min(dprc[i][j],dprc[i][j+1]);
            dprc[i][j]+=v[i][j];
        }
        for(long long j=1;j<=m;j++)
        {
            dp2[i][j] = dpr1[i][j]+dprc[i][j]-v[i][j];
            if(i<n) dp2[i][j] = min(dp2[i][j],dp2[i+1][j]+v[i][j]);
        }
    }
    long long ans = 1e12;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            ans = min(ans,dp1[i][j]+dp2[i][j]-v[i][j]);
        }
    }
    return ans;
}
int main()
{
    long long n,m,ans1,ans2;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)   for(long long j=1;j<=m;j++)   scanf("%lld",&v[i][j]),vv[m-j+1][i] = v[i][j];
    ans1 = solve(n,m);
    for(long long i=1;i<=m;i++) for(long long j=1;j<=n;j++)   v[i][j] = vv[i][j];
    ans2 = solve(m,n);
    printf("%lld\n",min(ans1,ans2));
    return 0;
}
/*
5 10
2 6 1 7 4 8 5 6 9 6
8 8 7 6 8 3 6 1 3 3
1 4 3 1 7 5 8 5 1 4
9 5 6 8 5 7 8 5 4 9
8 6 7 8 9 9 2 6 5 1
*/
