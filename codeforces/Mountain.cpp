#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
long long a[N];
long long f[N];
long long l[N];
long long r[N];
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
    long long n,ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),vec.push_back(a[i]);
    sort(vec.begin(),vec.end());    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    for(long long i=1;i<=n;i++)   a[i] = lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
    for(long long i=1;i<=n;i++)   l[i] = query(a[i]),upd(a[i]+1);
    memset(f,0,sizeof f);
    for(long long i=n;i>=1;i--)   r[i] = query(a[i]),upd(a[i]+1);
    for(long long i=1;i<=n;i++)   ans+=l[i]*r[i];
    printf("%lld\n",ans);
    return 0;
}
