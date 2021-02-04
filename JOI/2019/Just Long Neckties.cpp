#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int ans[N];
int sm[N*4];
pair< int,int > a[N];
int b[N];
void build(int l,int r,int now)
{
    if(l==r)    {sm[now] = max(a[l+1].first-b[l],0);return;}
    int mid = (l+r) >> 1;
    build(l,mid,now<<1),build(mid+1,r,now<<1|1);
    sm[now] = max(sm[now<<1],sm[now<<1|1]);;
}
void upd(int l,int r,int idx,int now)
{
    if(l>idx||r<idx)    return ;
    if(l==r)    {sm[now] = max(0,a[l].first-b[l]);return ;}
    int mid = (l+r) >> 1;
    upd(l,mid,idx,now<<1),upd(mid+1,r,idx,now<<1|1);
    sm[now] = max(sm[now<<1],sm[now<<1|1]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)   scanf("%d",&a[i].first),a[i].second = i;
    for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
    sort(a+1,a+n+2),sort(b+1,b+n+1);
    build(1,n,1);
    ans[a[1].second] = sm[1];
    for(int i=1;i<=n;i++)
    {
        upd(1,n,i,1);
        ans[a[i+1].second] = sm[1];
    }
    for(int i=1;i<=n+1;i++) printf("%d ",ans[i]);
    return 0;
}
