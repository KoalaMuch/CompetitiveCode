#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int mx = 1e7+4;
long long cnt[mx];
long long a[N];
int main()
{
    long long n,k,x,s = 0;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)   scanf("%lld",&x),++cnt[x],s+=x,a[i]=x;
    long long mean = s/k;
    if(s%k) ++mean;
    k-=n;
    for(long long i=1000000;i>=1&&k;i--)
    {
        if(!cnt[i]) continue;
        --cnt[i];
        k+=1;
        long long get = i/mean;
        if(i%mean) ++get;
        if(get>=k)
        {
            cnt[mean]+=k;
            if(i-k*mean!=0) cnt[i-k*mean]+=1;
            k = 0;
        }
        else
        {
            cnt[mean]+=get;
            if(i%mean)    cnt[i%mean]+=1,--k;
            k-=get;
        }
        if(cnt[i])   ++i;
    }
    long long ans = 0;
    for(long long i=1;i<=1000000;i++) ans+=(i*i*cnt[i]);
    printf("%lld\n",ans);
    return 0;
}
/*
1 3
9.
*/
