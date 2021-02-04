#include<bits/stdc++.h>
using namespace std;
long long dp[21][10][10];
long long s[21];
long long cal(long long num,long long ret = 0)
{
    if(num<=9)  return num+1;
    memset(dp,0,sizeof dp);
    long long n = ((long long)log10(num))+1;
    for(long long i=n;i>=1;i--,num/=10)   s[i] = num%10;
    long long st = 1e9;
    for(long long i=2;i<=n;i++)
    {
        if(s[i]==s[i-1])    st = min(st,i);
        if(i>2&&s[i]==s[i-2])   st = min(st,i);
    }
    for(long long i=1;i<s[1];i++)   for(long long j=0;j<=9;j++) dp[2][i][j] = i!=j;
    for(long long i=0;i<=s[2];i++)  dp[2][s[1]][i] = s[1]!=i;
    for(long long i=2;i<=n-1;i++)
    {
        for(long long j=0;j<=9;j++)
        {
            for(long long k=0;k<=9;k++)
            {
                for(long long l=0;l<=9;l++)
                {
                    if(j==l||k==l)  continue;
                    dp[i+1][k][l]+=dp[i][j][k];
                    if(i<st&&j==s[i-1]&&k==s[i]&&l>s[i+1]) --dp[i+1][k][l];
                }
            }
        }
    }
    for(long long i=0;i<=9;i++)   for(long long j=0;j<=9;j++)   ret+=dp[n][i][j];
    return ret;
}
long long split(long long n,long long ret = 0)
{
    for(long long st=9,i=0;i<=17;++i,st = st*10+9)
    {
        if(n<=st)   return ret+cal(n);
        ret+=cal(st);
    }
    return ret+cal(n);
}
int main()
{
    long long l,r;
    scanf("%lld %lld",&l,&r);
    long long ans = split(r);
    if(l)   ans-=split(l-1);
    printf("%lld\n",ans);
    return 0;
}
