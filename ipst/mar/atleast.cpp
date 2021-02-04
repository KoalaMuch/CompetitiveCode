#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct A
{
    long long l,r,v1,v2;
}sm[N*65];
long long root[N];
long long seq[N];
long long perm[N];
long long v[N];
long long qs[N];
long long cur;
long long clone(long long idx)  {sm[++cur] = sm[idx];return cur;}
long long upd(long long l,long long r,long long idx,long long now,long long val)
{
    long long newnow = clone(now);
    if(l==r)
    {
        sm[newnow].v1++;
        sm[newnow].v2+=val;
        return newnow;
    }
    long long mid = (l+r) >> 1;
    if(idx<=mid)    sm[newnow].l = upd(l,mid,idx,sm[newnow].l,val);
    else            sm[newnow].r = upd(mid+1,r,idx,sm[newnow].r,val);
    sm[newnow].v1 = sm[sm[newnow].l].v1+sm[sm[newnow].r].v1;
    sm[newnow].v2 = sm[sm[newnow].l].v2+sm[sm[newnow].r].v2;
    return newnow;
}
long long get_Kth(long long p,long long q,long long l,long long r,long long val)
{
    if(l==r)    return l;
    long long mid = (l+r) >> 1;
    long long suml = sm[sm[q].l].v1-sm[sm[p].l].v1;
    if(suml>=val)  return get_Kth(sm[p].l,sm[q].l,l,mid,val);
    else           return get_Kth(sm[p].r,sm[q].r,mid+1,r,val-suml);
}
long long getsum(long long p,long long l,long long r,long long ll,long long rr)
{
    if(l>rr||r<ll)  return 0;
    if(l>=ll&&r<=rr)    return sm[p].v2;
    long long mid = (l+r) >> 1;
    return getsum(sm[p].l,l,mid,ll,rr)+getsum(sm[p].r,mid+1,r,ll,rr);
}
bool cmp(long long a,long long b)
{
    if(v[a]!=v[b])  return v[a]<v[b];
    return a<b;
}
int main()
{
    long long n,q;
    scanf("%lld %lld",&n,&q);
    for(long long i=1;i<=n;i++)   scanf("%lld",&v[i]),perm[i] = i,qs[i] = v[i]+qs[i-1];
    sort(perm+1,perm+n+1,cmp);
    for(long long i=1;i<=n;i++)   seq[perm[i]] = i;
    for(long long i=1;i<=n;i++)   root[i] = upd(1,n,seq[i],root[i-1],v[i]);
    while(q--)
    {
        long long l,r;
        double want;
        scanf("%lld %lld %lf",&l,&r,&want);
        long long low = 0,high = r-l+1,len = r-l+1;
        while(low<high)
        {
            long long mid = (low+high) >> 1;
            long long st = get_Kth(root[l-1],root[r],1,n,1),en = get_Kth(root[l-1],root[r],1,n,mid);
            long long sum = (qs[r]-qs[l-1])-(getsum(root[r],1,n,st,en)-getsum(root[l-1],1,n,st,en));
            if(!mid)    sum = qs[r]-qs[l-1];
            if(sum/(1.0*(len-mid))>=want)   high=mid;
            else                            low=mid+1;
        }
        printf(low==len&&want>0 ? "-1\n" : "%lld\n",low);
    }
    return 0;
}
/*
11 3
6 5 4 3 2 1 2 3 4 5 6
1 11 3
2 10 3.55
5 8 3.5

11 3
5 5 5 5 5 5 5 5 5 5 5
1 1 5
1 2 5
1 3 5
*/
