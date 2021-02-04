#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long l[N];
long long r[N];
long long a[N];
int main()
{
    long long T,n;
    scanf("%lld",&T);
    while(T--)
    {
        long long ans = 0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)   scanf("%lld",a+i);
        for(long long i=1;i<=n;i++)
        {
            l[i] = i-1;
            while(l[i]!=0&&a[i]<=a[l[i]]) l[i] = l[l[i]];
        }
        for(long long i=n;i>=1;i--)
        {
            r[i] = i+1;
            while(r[i]!=n+1&&a[i]<=a[r[i]]) r[i] = r[r[i]];
        }
        for(long long i=1;i<=n;i++)   ans = max(ans,a[i]*(r[i]-l[i]-1));
        printf("%lld\n",ans);
    }
    return 0;
}
