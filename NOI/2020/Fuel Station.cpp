#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
struct A
{
    long long x,a,b,i;
};
A a[N];
bool cmpx(A a,A b)
{
    return a.x<b.x;
}
bool cmpb(A a,A b)
{
    return a.b<b.b;
}
long long sm[N*4];
long long lz[N*4];
void push(long long l,long long r,long long now)
{
    if(!lz[now])    return;
    sm[now]+=lz[now];
    if(l!=r)    lz[now<<1]+=lz[now],lz[now<<1|1]+=lz[now];
    lz[now] = 0;
}
void upd(long long l,long long r,long long ll,long long rr,long long now,long long v)
{
    push(l,r,now);
    if(l>rr||r<ll)  return ;
    if(l>=ll&&r<=rr)
    {
        lz[now]+=v;
        push(l,r,now);
        return ;
    }
    long long mid = (l+r) >> 1;
    upd(l,mid,ll,rr,now<<1,v),upd(mid+1,r,ll,rr,now<<1|1,v);
    sm[now] = min(sm[now<<1],sm[now<<1|1]);
}
stack< A > st;
int main()
{
    long long n,goal;
    scanf("%lld %lld",&n,&goal);
    long long ans = goal;
    for(long long i=2;i<=n+1;i++) scanf("%lld %lld %lld",&a[i].x,&a[i].a,&a[i].b);
    a[n+2].x = goal;
    n+=2;
    sort(a+1,a+n+1,cmpx);
    long long lst = 0;
    a[n+1].x = goal;
    for(long long i=1;i<=n;i++)
    {
        long long v = lst-(a[i+1].x-a[i].x)+a[i].a;
        upd(1,n,i,i,1,v);
        a[i].i = i;
        lst = v;
    }
    sort(a+1,a+n+1,cmpb);
    for(long long i=1;i<=n;i++)
    {
        while(!st.empty()&&st.top().b<a[i].b)
        {
            upd(1,n,st.top().i,n,1,-st.top().a);
            st.pop();
        }
        upd(1,n,1,n,1,a[i].b-a[i-1].b);
        if(sm[1]>=0)    ans = min(ans,a[i].b-sm[1]);
        st.push(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
