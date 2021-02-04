#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,k,x;
    scanf("%lld",&t);
    while(t--)
    {
        long long sum = 0,ans = 0;
        scanf("%lld %lld",&n,&k);
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            if(i>1)
            {
                long long need = 100*x-k*sum,add = 0;
                if(need>0)  add = need/k+(need%k!=0);
                sum+=add;
                ans+=add;
            }
            sum+=x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
