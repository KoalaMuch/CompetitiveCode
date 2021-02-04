#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[N][3];
char s[N];
int get(char c)
{
    if(c=='J')  return 0;
    else if(c=='O') return 1;
    return 2;
}
int main()
{
    int n,k;
    int ans = 1e9;
    scanf("%d %d %s",&n,&k,s+1);
    for(int i=1;i<=n;i++)
    {
        dp[i][get(s[i])]++;
        for(int j=0;j<3;j++)    dp[i][j]+=dp[i-1][j];
    }
    for(int i=1;i<=n;i++)
    {
        int cur = i,l = i,r = n+1;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(dp[mid][0]-dp[cur-1][0]<k)   l=mid+1;
            else                            r=mid;
        }
        if(l==n+1)  continue;
        cur = l+1,l = cur,r = n+1;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(dp[mid][1]-dp[cur-1][1]<k)   l=mid+1;
            else                            r=mid;
        }
        if(l==n+1)  continue;
        cur = l+1,l = cur,r = n+1;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            if(dp[mid][2]-dp[cur-1][2]<k)   l=mid+1;
            else                            r=mid;
        }
        if(l==n+1)  continue;
        ans = min(ans,l-i+1-3*k);
    }
    printf(ans==1e9 ? "-1\n" : "%d\n",ans);
    return 0;
}
/*
10 2
JJOOJJOOII

    10 2
    JJIIJJOOII
*/
