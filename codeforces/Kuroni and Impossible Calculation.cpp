#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
int main()
{
    long long n,m,ans = 1,sum = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n>m) return printf("0\n"),0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            ans = ans*abs(a[i]-a[j])%m;
        }
    }
    printf("%lld\n",ans%m);
    return 0;
}
