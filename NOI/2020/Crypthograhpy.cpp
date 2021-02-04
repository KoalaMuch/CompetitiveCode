#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
const long long mod = 1e9+7;
long long f[N];
long long fac[N];
long long a[N];
vector< long long > vec;
void upd(long long i)
{
    while(i<N)  ++f[i],i+=i&-i;
}
long long query(long long i,long long ret = 0)
{
    while(i)    ret+=f[i],i-=i&-i;
    return ret;
}
int main()
{
    fac[0] = 1;
    long long n;
    long long ans = 1;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),vec.push_back(a[i]),fac[i] = i*fac[i-1]%mod;
    sort(vec.begin(),vec.end()); vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    for(long long i=1;i<=n;i++)   a[i] = lower_bound(vec.begin(),vec.end(),a[i])-vec.begin()+1;
    for(long long i=1;i<=n;i++)
    {
        long long cur = a[i]-query(a[i]);
        ans=(ans+(cur-1)*fac[n-i])%mod;
        upd(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
