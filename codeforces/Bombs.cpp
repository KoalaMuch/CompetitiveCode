#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int f[N];
int where[N];
int sm[N*4];
int a[N];
int b[N];
void upf(int i,int v)
{
    while(i<N)    f[i]+=v,i+=i&-i;
}
int getf(int t,int i,int ret = 0)
{
    while(i)    ret+=f[i],i-=i&-i;
    return ret;
}
void updsm(int l,int r,int idx,int now,int v)
{
    if(l==r)    {sm[now] = v;return;}
    int mid = (l+r) >> 1;
    if(idx<=mid)    updsm(l,mid,idx,now<<1,v);
    else            updsm(mid+1,r,idx,now<<1|1,v);
    sm[now] = max(sm[now<<1],sm[now<<1|1]);
}
int getmax(int l,int r,int ll,int rr,int now)
{
    if(l>rr||r<ll)  return 0;
    if(l>=ll&&r<=rr)    return sm[now];
    int mid = (l+r) >> 1;
    return max(getmax(l,mid,ll,rr,now<<1),getmax(mid+1,r,ll,rr,now<<1|1));
}
int sm2[N*4];
void upkth(int l,int r,int idx,int now)
{
    if(l==r)    {sm2[now] = 1;return;}
    int mid = (l+r) >> 1;
    if(idx<=mid)    upkth(l,mid,idx,now<<1);
    else            upkth(mid+1,r,idx,now<<1|1);
    sm2[now] = sm2[now<<1]+sm2[now<<1|1];
}
int getkth(int l,int r,int now,int want)
{
    if(l==r)    return l;
    int mid = (l+r) >> 1;
    if(sm2[now<<1]>=want)    return getkth(l,mid,now<<1,want);
    else                     return getkth(mid+1,r,now<<1|1,want-sm2[now<<1]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),updsm(1,n,i,1,a[i]),where[a[i]]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(i==1)    {printf("%d ",n);continue;}
        upkth(1,n,b[i-1],1);
        int l = 1,r = i-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            int now = getkth(1,n,1,mid);
            int s = getf(1,now);
            if(mid<=s)    l=mid+1;
            else          r=mid;
        }
        int now = getkth(1,n,1,l);
        int mx = getmax(1,n,1,now,1);
        updsm(1,n,where[mx],1,0);
        printf("%d ",sm[1]);
        upf(where[mx],1);
    }
    return 0;
}
/*
6
2 3 6 1 5 4
5 2 1 4 6 3

6
6 5 4 3 2 1
6 5 4 3 2 1
*/
