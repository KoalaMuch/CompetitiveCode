#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long t1[N];
long long t2[N];
long long dp1[N];
long long dp2[N];
long long v;
struct A
{
    long long x,t,i;
};
A arr[N];
bool cmp1(A a,A b)
{
    if(a.x!=b.x)    return a.x<b.x;
    return v*a.t-a.x<v*b.t-b.x;
}
bool cmp2(A a,A b)
{
    if(a.x!=b.x)    return a.x>b.x;
    return v*a.t+a.x<v*b.t+b.x;
}
bool cmp3(A a,A b)
{
    return a.t<b.t;
}
int main()
{
    long long q,n;
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld",&n,&v);
        for(long long i=1;i<=n;i++) scanf("%lld %lld",&arr[i].x,&arr[i].t),arr[i].i=i;
        sort(arr+1,arr+n+1,cmp1);
        for(long long i=1;i<=n;i++) t1[arr[i].i] = i;
        sort(arr+1,arr+n+1,cmp2);
        for(long long i=1;i<=n;i++) t2[arr[i].i] = i;
        sort(arr+1,arr+n+1,cmp3);
        long long m = 0 ;
        for(long long i=1;i<=n;i++)
        {
            long long l = 0,r = m;
            while(l<r)
            {
                long long mid = (l+r+1) >> 1;
                if(t1[i]>dp1[mid]||t2[i]>dp2[mid])    l=mid;
                else                                  r=mid-1;
            }
            if(l==m)    dp1[l+1] = t1[i],dp2[l+1] = t2[i],++m;
            else        dp1[l+1] = min(dp1[l+1],t1[i]),dp2[l+1] = min(dp2[l+1],t2[i]);
        }
        printf("%lld\n",m);
    }
    return 0;
}
/*
3
3 5
5 1
0 2
5 2
4 1
1 1
1 2
2 2
3 3
3 5
0 1
5 2
0 3

vti-xi>=vtj-xj //xi>=xj
vti+xi>=vtj+xj //xi<xj

5 2
2 4 1 1 1 1 2 2 2 3 3 4 1 1 1 1 2 2 2 3 3*/
