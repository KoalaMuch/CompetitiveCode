#include<bits/stdc++.h>
using namespace std;
map< long long,long long > mp;
int main()
{
    long long n,k;
    scanf("%lld %lld",&n,&k);
    mp[n] = 1;
    if(mp[n]>=k)    return printf("%lld\n",n),0;
    for(long long i=n-1;i>=n-3;i--)
    {
        if(i<=n/2)   break;
        mp[i] = (i%2==0)*mp[i+1]+mp[i<<1]+1;
        if(mp[i]>=k)    return printf("%lld\n",i),0;
    }
    while(1)
    {
        long long newn = n>>1;
        for(long long i=newn;i>=newn-3;i--)
        {
            if(i<=newn/2)  break;
            mp[i] = 1;
            if((i<<1)!=n&&(i<<1)!=n-1)   mp[i] = mp[i]+mp[n-2-(n%2)];
            else                         mp[i] = mp[i]+mp[i<<1];
            if(i%2==0&&!mp[i+1])         mp[i] = mp[i]+mp[n-2-(n%2==0)];
            else if(i%2==0)              mp[i] = mp[i]+mp[i+1];
            if(mp[i]>=k)    return printf("%lld\n",i),0;
        }
         n = newn;
    }
    return 0;
}
