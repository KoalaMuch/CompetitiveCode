#include<bits/stdc++.h>
using namespace std;
long long ans[10005];
long long far[10005];
int main()
{
    long long u,v,len = 0;
    scanf("%lld %lld",&u,&v);
    if(u==0&&v==0)  return printf("0\n"),0;
    if(u>v) return printf("-1\n"),0;
    v-=u;
    ans[1] = u;
    for(long long i=62;i>=0;i--)
    {
        far[i] = v/(1ll<<i);
        if(far[i]%2)    --far[i];
        v-=(1ll<<i)*far[i];
        if((1ll<<i)&u)
        {
            len = max(len,far[i]+1);
            for(long long j=2;j<=far[i]+1;j++)  ans[j]|=(1ll<<i);
        }
        else
        {
            len = max(len,far[i]);
            for(long long j=1;j<=far[i];j++)    ans[j]|=(1ll<<i);
        }
    }
    if(v)   return printf("-1\n"),0;
    printf("%lld\n",len);
    for(long long i=1;i<=len;i++)   printf("%lld ",ans[i]);
    return 0;
}
/*
2 8
2 3 3

2 4
2 1 1
*/
