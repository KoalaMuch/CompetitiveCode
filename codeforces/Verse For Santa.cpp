#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int main()
{
    long long T,n,s;
    scanf("%lld",&T);
    while(T--)
    {
        long long ans1 = 0,sum = 0,ans2 = 0,id = 0,skip = 0;
        scanf("%lld %lld",&n,&s);
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
        for(long long i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum<=s)          ans1 = i;
        }
        sum = 0;
        for(long long i=1;i<=n;i++)
        {
            sum+=a[i];
            if(a[i]>a[id])  id = i;
            if(sum-a[id]<=s)   ans2 = i-1,skip = id;
        }
        printf(ans1>=ans2 ? "0\n" : "%lld\n",skip);
    }
    return 0;
}
