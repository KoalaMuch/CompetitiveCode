#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q,n,k,a,b,c,d,conc,prof;
    scanf("%lld",&q);
    while(q--)
    {
        long long ans = 1e18;
        scanf("%lld %lld %lld %lld %lld %lld",&n,&k,&a,&b,&c,&d);
        if(a>c) swap(a,c),swap(b,d);
        conc = max(0ll,c-b);
        prof = (max(b,d)-a)-max(min(b,d)-c,0ll);
        k-=n*max(min(b,d)-c,0ll);
        k = max(k,0ll);
        for(long long i=1;i<=n;i++)
        {
            long long get = i*prof,now;
            if(get>k)
            {
                long long tmpk = max(k-(i-1)*prof,0ll);
                now = (conc+prof)*(i-1)+conc+tmpk;
            }
            else        now = (conc+prof)*i+2*(k-get);
            ans = min(ans,now);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
3
3 5
1 2
3 4
2 1000000000
1 1
999999999 999999999
10 3
5 10
7 8
*/
