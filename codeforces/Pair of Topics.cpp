#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long f[N*2];
long long a[N];
long long b[N];
vector< long long > num;
void upd(long long i,long long v)
{
    while(i<N*2)  f[i]+=v,i+=i&-i;
}
long long get(long long i,long long ans = 0)
{
    while(i)    ans+=f[i],i-=i&-i;
    return ans;
}
int main()
{
    long long n,ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)   scanf("%lld",&b[i]);
    for(long long i=1;i<=n;i++)   num.push_back(a[i]-b[i]),num.push_back(b[i]-a[i]);
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end())-num.begin());
    for(long long i=1;i<=n;i++)
    {
        long long idx = lower_bound(num.begin(),num.end(),b[i]-a[i])-num.begin()+1;
        ans = ans+get(idx);
        idx = lower_bound(num.begin(),num.end(),a[i]-b[i])-num.begin()+1;
        upd(1,1);
        upd(idx,-1);
    }
    printf("%lld\n",ans);
    return 0;
}
