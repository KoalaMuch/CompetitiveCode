#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
int main()
{
    long long q,n;
    long long k;
    scanf("%lld",&q);
    while(q--)
    {
        long long mn = 1e9,mx = -1e9;
        scanf("%lld %lld",&n,&k);
        k%=2;
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),mn = min(mn,a[i]),mx = max(mx,a[i]);
        for(long long i=1;i<=n;i++)
        {
            if(k==1)    a[i] = mx-a[i];
            else        a[i] = a[i]-mn;
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
