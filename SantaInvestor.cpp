#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int dp[N];
int main()
{
    int n,a,mx = -1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        dp[i] = max(dp[i-1],a+mx);
        mx = max(mx,-a+dp[i-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}   