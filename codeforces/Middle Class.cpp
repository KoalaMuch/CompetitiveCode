#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int main()
{
    long long T,n,want;
    scanf("%lld",&T);
    while(T--)
    {
        long long mx = 0,s = 0;
        scanf("%lld %lld",&n,&want);
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),a[i]*=-1;
        sort(a+1,a+n+1);
        for(long long i=1;i<=n;i++)
        {
            a[i]*=-1;
            s+=a[i];
            if(s/i>=want)   mx = i;
        }
        printf("%lld\n",mx);
    }
    return 0;
}
