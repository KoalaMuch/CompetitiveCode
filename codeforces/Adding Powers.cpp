#include<bits/stdc++.h>
using namespace std;
const int N = 35;
long long p[N+N];
long long a[N];
long long use[N+N];
int main()
{
    long long T,n,k;
    scanf("%lld",&T);
    while(T--)
    {
        long long lim,ch = 0;
        memset(use,0,sizeof use);
        scanf("%lld %lld",&n,&k);
        p[0] = 1;
        for(long long i=1;i<=70;i++)
        {
            p[i] = p[i-1]*k;
            if(p[i]>1e16)   {lim=i;break;}
        }
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
        for(long long i=lim;i>=0&&!ch;i--)
        {
            for(long long j=1;j<=n&&!ch;j++)
            {
                while(a[j]>=p[i])
                {
                    a[j]-=p[i];
                    ++use[i];
                    if(use[i]>1)    {ch=1;break;}
                }
            }
        }
        printf(ch ? "NO\n" : "YES\n");
    }
    return 0;
}
/*
1
3 9
0 59049 810
*/
