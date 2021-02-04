#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long cnt[N];
long long a[N];
int main()
{
    long long n;
    long long ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),++cnt[a[i]];
    for(long long i=1;i<=n;i++)   ans+=(cnt[i]*(cnt[i]-1))>>1;
    for(long long i=1;i<=n;i++)
    {
        printf("%lld\n",ans-(cnt[a[i]]-1));
    }
    return 0;
}
