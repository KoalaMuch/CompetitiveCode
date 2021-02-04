#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
map< long long ,long long > mp;
int main()
{
    long long n,s = 0,cur = 0,ans = 0;
    scanf("%lld",&n);
    mp[0] = 1;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s+=a[i];
        cur = max(cur,mp[s]);
        ans+=i-cur;
        mp[s] = i+1;
    }
    printf("%lld\n",ans);
    return 0;
}
