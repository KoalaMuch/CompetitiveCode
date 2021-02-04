#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
char s[N][N];
int dp1[N][N];
int dp2[N][N];
int lvl[N][N];
int l[N];
int r[N];
int main()
{
    int n,m;
    long long ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   scanf(" %s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            l[j] = 1;
            if(s[i][j]==s[i][j-1])  l[j]+=l[j-1];
        }
        for(int j=m;j>=1;j--)
        {
            r[j] = 1;
            if(s[i][j]==s[i][j+1])  r[j]+=r[j+1];
        }
        for(int j=1;j<=m;j++)   lvl[i][j] = min(l[j],r[j]);
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(s[i][j]==s[i-1][j]) dp1[i][j] = min(dp1[i-1][j]+1,lvl[i][j]);
             else                   dp1[i][j] = 1;
         }
     }
     for(int i=n;i>=1;i--)
     {
         for(int j=1;j<=m;j++)
         {
             if(s[i][j]==s[i+1][j]) dp2[i][j] = min(dp2[i+1][j]+1,lvl[i][j]);
             else                   dp2[i][j] = 1;
         }
     }
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)  ans+=min(dp1[i][j],dp2[i][j]);
     }
     printf("%lld\n",ans);
    return 0;
}
