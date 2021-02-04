#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
int dp[N][N];
char s[N];
int main()
{
    int n,m;
    long long ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",s+1);
        int O = 0;
        for(int j=m;j>=1;j--)
        {
            dp[i][j] = dp[i-1][j];
            if(s[j]=='J')   dp[i][j]+=O;
            else if(s[j]=='O')  ++O;
            else            ans+=dp[i-1][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
