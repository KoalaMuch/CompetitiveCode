#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char s[N];
int a[N];
int dp[N];
int main()
{
    int cur = 0,now = 0,n;
    char last = '2';
    scanf("%d %s",&n,s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]==s[i-1]||s[i]=='?'||s[i]==last)    ++now;
        else                                         now = 1+cur,last = s[i];
        if(s[i]=='?')   ++cur;
        else            cur = 0,last = s[i];
        a[i] = now;
    }
    for(int i=n;i>=1;i--)   dp[i] = max(dp[i+1],a[i]);
    for(int i=1;i<=n;i++)
    for(int i=1;i<=n;i++)
    {
        int ans = 0;
        cur = 0;
        while(cur<=n)
        {
            int l = cur,r = n+1;
            while(l<r)
            {
                int mid = (l+r) >> 1;
                if(dp[mid]<i)   l = mid+1;
                else            r = mid;
            }
            cur = l;
            if(cur==n+1)    break;
            else            ++ans;
        }
        printf("%d ",ans);
    }
    return 0;
}
