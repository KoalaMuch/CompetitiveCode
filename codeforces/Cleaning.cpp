#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct A
{
    long long mino,mine;
};
A sm[N*4];
long long val[N];
long long a[N];
long long n;
void build(long long l,long long r,long long now)
{
    if(l==r)
    {
        if(l%2) sm[now].mino = val[l],sm[now].mine = 1e15;
        else    sm[now].mine = val[l],sm[now].mino = 1e15;
        return ;
    }
    long long mid = (l+r)>>1;
    build(l,mid,now<<1);
    build(mid+1,r,now<<1|1);
    sm[now].mine = min(sm[now<<1].mine,sm[now<<1|1].mine);
    sm[now].mino = min(sm[now<<1].mino,sm[now<<1|1].mino);
}
A query(long long l,long long r,long long ll,long long rr,long long now)
{
    if(l>rr||r<ll)  return {(long long)1e15+1,(long long)1e15+1};
    if(l>=ll&&r<=rr)
    {
        return sm[now];
    }
    long long mid = (l+r) >> 1;
    A a = query(l,mid,ll,rr,now<<1),b = query(mid+1,r,ll,rr,now<<1|1);
    return {min(a.mino,b.mino),min(a.mine,b.mine)};
}
bool play(long long i,long long j)
{
    long long v = a[j]-a[i],a1,b1,a2,b2;
    A f = query(1,n,i,j-1,1),s = query(1,n,j,n,1);
    a1 = -v,b1 = v,a2 = -v,b2 = v;
    if(i%2) swap(a1,b1),swap(a2,b2);
    if(j%2) a2-=v,b2+=v;
    else    a2+=v,b2-=v;
    if(f.mino+a1<0 || f.mine+b1<0 || s.mino+a2<0 || s.mine+b2<0)    return false;
    if(n%2 && val[n]+a2!=0)   return false;
    if(n%2==0 && val[n]+b2!=0)    return false;
    return true;
}
int main()
{
    long long q;
    scanf("%lld",&q);
    while(q--)
    {
        bool ch = false;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),val[i] = a[i]-val[i-1];
        build(1,n,1);
        for(long long i=1;i<=n;i++)
        {
            if(play(1,i))   ch = true;
        }
        for(long long i=1;i<=n;i++)
        {
            if(play(i,n))   ch = true;
        }
        printf( (ch) ? "YES\n" : "NO\n");
    }
    return 0;
}
