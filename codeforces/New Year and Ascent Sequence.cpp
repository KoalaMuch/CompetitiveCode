#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long mn[N];
long long mx[N];
vector< long long > MN;
vector< long long > MX;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long ans = n*n;
    for(long long i=1;i<=n;i++)
    {
        long long x,num,ch = 0;
        mn[i] = 1e6;
        scanf("%lld",&x);
        for(long long j=1;j<=x;j++)    scanf("%lld",&num),mn[i] = min(mn[i],num),mx[i] = max(mx[i],num),ch|=num>mn[i];
        if(!ch) MN.push_back(mn[i]),MX.push_back(mx[i]);
    }
    sort(MN.begin(),MN.end()),sort(MX.begin(),MX.end());
    long long j = 0;
    for(auto &x:MN)
    {
        while(j!=MX.size()&&MX[j]<=x) ++j;
        ans-=j;
    }
    printf("%lld\n",ans);
    return 0;
}
