#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long lc[N];
long long a[N];
long long b[N];
long long c[N];
int main()
{
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        long long ans = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)   scanf("%lld",&c[i]);
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
        for(long long i=1;i<=n;i++)   scanf("%lld",&b[i]);
        for(long long i=1;i<=n;i++)
        {
            if(i==1)    lc[i] = abs(a[i+1]-b[i+1]);
            else
            {
                if(a[i]==b[i])  lc[i] = 1+c[i];
                else if(i==2)   lc[i] = c[i]+abs(a[i]-b[i])+1;
                else            lc[i] = c[i]+max(lc[i-1]-abs(a[i]-b[i])+1,abs(a[i]-b[i])+1);
            }
            if(i!=1)    ans = max(ans,lc[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
