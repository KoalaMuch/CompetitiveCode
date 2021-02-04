#include<bits/stdc++.h>
using namespace std;
const int N = 355;
long long qs[N];
long long dp[N][N];
long long path[N][N];
long long a[N];
vector< long long > p;
int main()
{
    long long n,bogie;
    long long ans = 0;
    scanf("%lld %lld",&n,&bogie);
    for(long long i=1;i<=n;i++)   scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)   qs[i] = a[i]+qs[i-1];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=2*bogie;j++)
        {
            dp[i][j] = 1e18;
            for(long long k=1;k<=i;k++)
            {
                if(k-1>0&&j-1==0)   continue;
                long long v = dp[k-1][j-1]+(qs[i]-qs[k-1])*(i-k);
                if(v<=dp[i][j])  dp[i][j] = v,path[i][j] = k;
            }
        }
    }
    long long cur = bogie*2,now = n,sum = 0;
    while(now)   p.push_back(now-path[now][cur]+1),now = path[now][cur]-1,--cur;
    sort(p.begin(),p.end());
    for(long long i=0;i<bogie;i++)    sum+=2*p[i]*p[2*bogie-i-1];
    printf("%lld\n",dp[n][2*bogie]+sum);
    return 0;
}
/*
6 2
9 10 | 12 13 | 14 | 15
(52)

6 1
5 7 12 13 20 34
(181)

10 1
1 1 1 1 2 2 2 3 3 3

6 1
1 2 3 4 4 5
(55)
*/
