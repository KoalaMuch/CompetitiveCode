#include<bits/stdc++.h>
using namespace std;
long long x[65];
long long y[65];
long long d[65][65];
int main()
{
    long long ax,ay,bx,by,xs,ys,T,n,mx = 0;
    scanf("%lld %lld %lld %lld %lld %lld",&x[0],&y[0],&ax,&ay,&bx,&by);
    scanf("%lld %lld %lld",&xs,&ys,&T);
    n = 0;
    for(long long i=1;i<=62;i++)
    {
        if(x[i-1]>2e16||y[i-1]>2e16)  break;
        n=i;
        x[i] = ax*x[i-1]+bx;
        y[i] = ay*y[i-1]+by;
    }
    for(long long i=0;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            d[i][j] = d[i][j-1]+x[j]-x[j-1]+y[j]-y[j-1];
        }
    }
    for(long long i=0;i<=n;i++)
    {
        for(long long j=i;j>=0;j--)
        {
            long long D = d[j][i]+abs(xs-x[i])+abs(ys-y[i]);
            if(D<=T)    mx = max(mx,i-j+1);
            for(long long k=i+1;k<=n;k++)
            {
                for(long long l=k;l<=n;l++)
                {
                    if(D+x[k]-x[j]+y[k]-y[j]+d[k][l]<=T)
                    {
                        mx = max(mx,k-j+1);
                    }
                }
            }
        }
    }
    printf("%lld\n",mx);
    return 0;
}
