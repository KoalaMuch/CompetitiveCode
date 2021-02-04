#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int dp[1<<9];
int idx[1<<9];
int v[N];
int f,s,n,m;
int a[N][9];
void solve(int want)
{
    f = s = 0;
    memset(idx,0,sizeof idx);
    memset(dp,0,sizeof dp);
    memset(v,0,sizeof v);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)    if(a[i][j]>=want)   v[i]|=(1<<j);
        idx[v[i]] = i;
        dp[v[i]] = 1;
    }
    for(int i=(1<<m)-1;i>=1;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(((1<<j)&i)&&dp[i])    idx[i^(1<<j)] = idx[i],dp[i^(1<<j)] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[((1<<m)-1)^v[i]]) {f = i,s = idx[((1<<m)-1)^v[i]];break;}
    }
}
int main()
{
    int l = 0,r = 1e9+5;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   for(int j=0;j<m;j++)    scanf("%d",&a[i][j]);
    while(l<r)
    {
        int mid = (l+r+1) >> 1;
        solve(mid);
        if(!f)   r=mid-1;
        else     l=mid;
    }
    solve(l);
    printf("%d %d\n",f,s);
    return 0;
}
