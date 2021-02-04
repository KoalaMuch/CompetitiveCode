#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N];
int tmp[N];
int main()
{
    int n,a,s = 0;
    scanf("%d",&n);
    for(int i=1;i<=100000;i++)  dp[i] = tmp[i] = -1e5;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(int j=0;j<=s;j++)
        {
            tmp[abs(j-a)] = max(tmp[abs(j-a)],dp[j]+a);
            tmp[j+a] = max(tmp[j+a],dp[j]+a);
        }
        s+=a;
        for(int j=0;j<=s;j++)   dp[j] = max(dp[j],tmp[j]),tmp[j] = -1e5;
        tmp[0] = 0;
    }
    printf("%d\n",s-dp[0]/2);
    return 0;
}
