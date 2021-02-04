#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
struct A
{
    long long a[128][128];
};
A p;
A ans;
long long dp[10];
long long lim;
A mul(A a,A b)
{
    A tmp;
    for(long long i=0;i<lim;i++)
    {
        for(long long j=0;j<lim;j++)
        {
            tmp.a[i][j] = 0;
            for(long long k=0;k<lim;k++)
            {
                tmp.a[i][j] = (tmp.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return tmp;
}
int main()
{
    long long r,c;
    scanf("%lld %lld",&r,&c);
    lim = 1<<r;
    for(long long i=0;i<lim;i++)
    {
        for(long long j=0;j<lim;j++)
        {
            dp[0] = 1;
            for(long long k=1;k<=r;k++)
            {
                dp[k] = 0;
                long long v = k-1;
                if(!(1<<v&i))   dp[k] = dp[k-1];
                else
                {
                    if(!(1<<v&j))  dp[k] = dp[k-1];
                    if(v&&(1<<(v-1)&i)) dp[k] = (dp[k]+dp[k-2])%mod;
                }
            }
            p.a[j][i] = dp[r];
        }
    }
    memset(ans.a,0,sizeof ans.a);
    for(long long i=0;i<lim;i++)
    {
        long long con = 0,ch = 0;
        for(long long j=0;j<r;j++)
        {
            if(1<<j&i)  ++con;
            else if(con%2)  ch = 1;
        }
        ch|=con%2;
        if(!ch) ans.a[0][i] = 1;
    }
    --c;
    while(c)
    {
        if(c&1) ans = mul(ans,p);
        c>>=1;
        p = mul(p,p);
    }
    long long sum = 0;
    for(long long i=0;i<lim;i++)  sum = (sum+ans.a[0][i])%mod;
    printf("%lld\n",sum);
    return 0;
}
