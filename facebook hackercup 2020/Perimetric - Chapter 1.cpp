#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const long long mod = 1e9+7;
long long l[N];
long long h[N];
map< long long ,long long > mp;
int main()
{
    long long q,n,k,w,al,bl,cl,dl,ah,bh,ch,dh,run = 0;
    scanf("%lld",&q);
    while(q--)
    {
        ++run;
        long long ans = 1ll;
        scanf("%lld %lld %lld",&n,&k,&w);
        for(long long i=1;i<=k;i++)   scanf("%lld",&l[i]);
        scanf("%lld %lld %lld %lld",&al,&bl,&cl,&dl);
        for(long long i=1;i<=k;i++)   scanf("%lld",&h[i]);
        scanf("%lld %lld %lld %lld",&ah,&bh,&ch,&dh);
        for(long long i=k+1;i<=n;i++)
        {
            l[i] = (al*l[i-2]+bl*l[i-1]+cl)%dl+1;
            h[i] = (ah*h[i-2]+bh*h[i-1]+ch)%dh+1;
        }
        long long p = 0;
        for(long long i=1;i<=n;i++)
        {
            if(mp[l[i]]==0) p+=h[i];
            else if(h[i]>mp[l[i]])  p+=h[i]-mp[l[i]];
            for(long long j=1;j<w;j++)
            {
                if(mp[l[i]+j]==0)
                {
                    mp[l[i]+j] = h[i];
                    p+=2;
                }
                else if(h[i]>mp[l[i]+j])    ++p,p-=mp[l[i]+j],mp[l[i]+j] = h[i];
            }
            p = p+h[i]+2;
            mp[l[i]+w] = h[i];
            ans = ans*p%mod;
        }
        mp.clear();
        printf("Case #%lld: %lld\n",run,ans);
    }
    return 0;
}
