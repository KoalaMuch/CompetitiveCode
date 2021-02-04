#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long len[N];
long long getnum(long long a,long long b)
{
    if(b&1ll) return a;
    if(b==(a-1)*2)  return 1;
    return b/2ll+1;
}
int main()
{
    long long T,n,l,r;
    for(long long i=1;i<=100000;i++)   len[i] = i*(i-1)+1;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&l,&r);
        for(long long i=l;i<=r;i++)
        {
            long long p = 1ll,q = 100000ll;
            while(p<q)
            {
                long long mid = (p+q) >> 1ll;
                if(len[mid]<i)  p = mid+1ll;
                else            q = mid;
            }
            printf("%lld ",getnum(p,i-len[p-1]));
        }
        printf("\n");
    }
    return 0;
}
/*
1
100000
9999900000
9999900001
*/
