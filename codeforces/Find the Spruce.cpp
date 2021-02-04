#include<bits/stdc++.h>
using namespace std;
const int N = 505;
char s[N];
int l[N][N];
int r[N][N];
int dp[N][N];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf(" %s",s+1);
            for(int j=1;j<=m;j++)
            {
                l[i][j] = l[i][j-1];
                if(s[j]=='*')   l[i][j] +=1;
                else            l[i][j] = 0;
            }
            for(int j=m;j>=1;j--)
            {
                r[i][j] = r[i][j+1];
                if(s[j]=='*')   r[i][j]+=1;
                else            r[i][j] = 0;
                dp[i][j] = min(dp[i-1][j]+1,min(l[i][j],r[i][j]));
                ans+=dp[i][j];
            }
            for(int j=1;j<=m;j++)   r[i][j] = l[i][j] = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
