#include<bits/stdc++.h>
#define mod 1000000000
using namespace std;
const int N = 5e5;
struct A
{
    long long sans,smx,smn,ans,mx,mn;

}sm[N*4];
long long lzmn[N*4];
long long lzmx[N*4];
stack< pair< long long,long long > > mx;
stack< pair< long long,long long > > mn;
A Merge(A a,A b,long long p)
{
    return {(a.sans+b.sans+a.ans*p)%mod,(a.smx+b.smx+a.mx*p)%mod,(a.smn+b.smn+a.mn*p)%mod,(a.ans+b.ans)%mod,(a.mx+b.mx)%mod,(a.mn+b.mn)%mod};
}
void upmx(long long l,long long r,long long ll,long long rr,long long now,long long v)
{
    long long len = (r-l+1);
    if(lzmn[now])
    {
        sm[now].sans = lzmn[now]*sm[now].smx%mod;
        sm[now].smn = (len*(len+1)/2%mod)*lzmn[now]%mod;
        sm[now].ans = lzmn[now]*sm[now].mx%mod;
        sm[now].mn = len*lzmn[now]%mod;
        if(l!=r)    lzmn[now<<1] = lzmn[now<<1|1] = lzmn[now];
        lzmn[now] = 0;
    }
    if(lzmx[now])
    {
        sm[now].sans = lzmx[now]*sm[now].smn%mod;
        sm[now].smx = (len*(len+1)/2%mod)*lzmx[now]%mod;
        sm[now].ans = lzmx[now]*sm[now].mn%mod;
        sm[now].mx = len*lzmx[now]%mod;
        if(l!=r)    lzmx[now<<1] = lzmx[now<<1|1] = lzmx[now];
        lzmx[now] = 0;
    }
    if(l>rr||r<ll)  return;
    if(l>=ll&&r<=rr)
    {
        sm[now].sans = v*sm[now].smn%mod;
        sm[now].smx = (len*(len+1)/2%mod)*v%mod;
        sm[now].mx = len*v%mod;
        sm[now].ans = v*sm[now].mn%mod;
        if(l!=r)    lzmx[now<<1] = lzmx[now<<1|1] = v;
        return ;
    }
    long long mid = (l+r) >> 1;
    upmx(l,mid,ll,rr,now<<1,v); upmx(mid+1,r,ll,rr,now<<1|1,v);
    sm[now] = Merge(sm[now<<1],sm[now<<1|1],r-mid);
}
void upmn(long long l,long long r,long long ll,long long rr,long long now,long long v)
{
    long long len = (r-l+1);
    if(lzmn[now])
    {
        sm[now].sans = lzmn[now]*sm[now].smx%mod;
        sm[now].smn = (len*(len+1)/2%mod)*lzmn[now]%mod;
        sm[now].ans = lzmn[now]*sm[now].mx%mod;
        sm[now].mn = len*lzmn[now]%mod;
        if(l!=r)    lzmn[now<<1] = lzmn[now<<1|1] = lzmn[now];
        lzmn[now] = 0;
    }
    if(lzmx[now])
    {
        sm[now].sans = lzmx[now]*sm[now].smn%mod;
        sm[now].smx = (len*(len+1)/2%mod)*lzmx[now]%mod;
        sm[now].ans = lzmx[now]*sm[now].mn%mod;
        sm[now].mx = len*lzmx[now]%mod;
        if(l!=r)    lzmx[now<<1] = lzmx[now<<1|1] = lzmx[now];
        lzmx[now] = 0;
    }
    if(l>rr||r<ll)  return;
    if(l>=ll&&r<=rr)
    {
        sm[now].sans = v*sm[now].smx%mod;
        sm[now].smn = (len*(len+1)/2%mod)*v%mod;
        sm[now].ans = v*sm[now].mx%mod;
        sm[now].mn = len*v%mod;
        if(l!=r)    lzmn[now<<1] = lzmn[now<<1|1] = v;
        return ;
    }
    long long mid = (l+r) >> 1;
    upmn(l,mid,ll,rr,now<<1,v); upmn(mid+1,r,ll,rr,now<<1|1,v);
    sm[now] = Merge(sm[now<<1],sm[now<<1|1],r-mid);
}
A query(long long l,long long r,long long ll,long long rr,long long now)
{
    long long len = (r-l+1);
    if(lzmn[now])
    {
        sm[now].sans = lzmn[now]*sm[now].smx%mod;
        sm[now].smn = (len*(len+1)/2%mod)*lzmn[now]%mod;
        sm[now].ans = lzmn[now]*sm[now].mx%mod;
        sm[now].mn = len*lzmn[now]%mod;
        if(l!=r)    lzmn[now<<1] = lzmn[now<<1|1] = lzmn[now];
        lzmn[now] = 0;
    }
    if(lzmx[now])
    {
        sm[now].sans = lzmx[now]*sm[now].smn%mod;
        sm[now].smx = (len*(len+1)/2%mod)*lzmx[now]%mod;
        sm[now].ans = lzmx[now]*sm[now].mn%mod;
        sm[now].mx = len*lzmx[now]%mod;
        if(l!=r)    lzmx[now<<1] = lzmx[now<<1|1] = lzmx[now];
        lzmx[now] = 0;
    }
    if(l>rr||r<ll)  return {-1,-1,-1,-1,-1,-1};
    if(l>=ll&&r<=rr)    return sm[now];
    long long mid = (l+r) >> 1;
    A a = query(l,mid,ll,rr,now<<1),b = query(mid+1,r,ll,rr,now<<1|1);
    if(a.sans==-1)   return b;
    if(b.sans==-1)   return a;
    return Merge(a,b,rr-mid);
}
int main()
{
    long long n,x,ans = 0;
    scanf("%lld",&n);
    mx.push({1e18,0});
    mn.push({0,0});
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        while(x>=mx.top().first)    mx.pop();
        while(x<=mn.top().first)    mn.pop();
        upmx(1,n,mx.top().second+1,n,1,x);
        upmn(1,n,mn.top().second+1,n,1,x);
        A a = query(1,n,1,i,1);
        ans = (ans+a.sans)%mod;
        mx.push({x,i});
        mn.push({x,i});
    }
    printf("%lld\n",ans);
    return 0;
}
/*
5
1 4 2 3 1

4
1 4 2 3
*/
