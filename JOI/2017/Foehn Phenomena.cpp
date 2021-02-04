#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long s,t;
struct A
{
    long long l,r;
    long long ans;
};
A sm[N*4];
long long lz[N*4];
void apply(long long now,long long l,long long r)
{
    if(!lz[now])    return ;
    sm[now].l+=lz[now];
    sm[now].r+=lz[now];
    if(l!=r)    lz[now<<1]+=lz[now],lz[now<<1|1]+=lz[now];
    lz[now] = 0;
}
A Merge(A a,A b)
{
    if(a.r<b.l) return {a.l,b.r,a.ans+b.ans-s*(b.l-a.r)};
    else        return {a.l,b.r,a.ans+b.ans+t*(a.r-b.l)};
}
void upd(long long l,long long r,long long ll,long long rr,long long now,long long v)
{
    apply(now,l,r);
    if(l>rr||r<ll)return ;
    if(l>=ll&&r<=rr)
    {
        lz[now]+=v;
        apply(now,l,r);
        return ;
    }
    long long mid = (l+r) >> 1;
    upd(l,mid,ll,rr,now<<1,v),upd(mid+1,r,ll,rr,now<<1|1,v);
    sm[now] = Merge(sm[now<<1],sm[now<<1|1]);
//    printf("%lld %lld %lld %lld %lld\n",l,r,sm[now].l,sm[now].r,sm[now].ans);
}
int main()
{
    long long n,q,l,r,x;
    scanf("%lld %lld %lld %lld",&n,&q,&s,&t);
    for(long long i=0;i<=n;i++)   scanf("%lld",&x),upd(0,n,i,i,1,x);
//    printf("%lld\n",sm[1].ans);
    while(q--)
    {
        scanf("%lld %lld %lld",&l,&r,&x);
        upd(0,n,l,r,1,x);
        printf("%lld\n",sm[1].ans);
    }
    return 0;
}
/*
3 5 1 2
0 4 1 8
1 2 2
1 1 -2
2 3 5
1 2 -1
1 3 5
*/
