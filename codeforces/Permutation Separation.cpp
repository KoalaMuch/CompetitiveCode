#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long qs1[N];
long long qs2[N];
long long a[N];
long long v[N];
long long f[N];
void upd(long long i,long long j)
{
    while(i<N)  f[i]+=j,i+=i&-i;
}
long long query(long long i,long long ret = 0)
{
    while(i)    ret+=f[i],i-=i&-i;
    return ret;
}
int main()
{
    long long n,mn=1e18;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)   scanf("%lld",&v[i]);
    for(long long i=1;i<=n;i++)   qs1[i] = v[i]+qs1[i-1],qs2[a[i]]=v[i];
    for(long long i=1;i<=n;i++)   qs2[i]+=qs2[i-1];
    for(long long i=1;i<=n-1;i++)
    {
        upd(a[i],v[i]);
        mn = min(mn,qs1[i]+qs2[i]-2*query(i));
    }
    printf("%lld\n",min(mn,min(v[1],v[n])));
    return 0;
}
