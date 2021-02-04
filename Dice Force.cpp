#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int dp[N][5005];
int cnt[5005];
int path[N][5005];
int ans[N];
int arr[N];
int mark[5005];
struct A
{
    int val,pos;
};
A sm[5005*4];
int lz[N];
void build(int l,int r,int now,int p)
{
    if(l==r)    {sm[now] = {dp[p][l],l};return;}
    int mid = (l+r) >> 1;
    build(l,mid,now<<1,p),build(mid+1,r,now<<1|1,p);
}
void upd(int l,int r,int ll,int rr,int now,int val)
{
    if(lz[now])
    {
        sm[now].val+=lz[now];
        if(l!=r)    lz[now<<1]+=lz[now],lz[now<<1|1]+=lz[now];
        lz[now] = 0;
    }
    if(l>rr||r<ll)    return ;
    if(l>=ll&&r<=rr)
    {
        sm[now].val+=val;
        if(l!=r)    lz[now<<1]+=val,lz[now<<1|1]+=val;
        return ;
    }
    int mid = (l+r) >> 1;
    upd(l,mid,ll,rr,now<<1,val),upd(mid+1,r,ll,rr,now<<1|1,val);
    if(sm[now<<1].val>sm[now<<1|1].val) sm[now] = sm[now<<1];
    else                                sm[now] = sm[now<<1|1];
}
A query(int l,int r,int ll,int rr,int now)
{
    if(lz[now])
    {
        sm[now].val+=lz[now];
        if(l!=r)    lz[now<<1]+=lz[now],lz[now<<1|1]+=lz[now];
        lz[now] = 0;
    }
    if(l>rr||r<ll)  return {0,0};
    if(l>=ll&&r<=rr)    return sm[now];
    int mid = (l+r) >> 1;
    A a = query(l,mid,ll,rr,now<<1),b = query(mid+1,r,ll,rr,now<<1|1);
    if(a.val>b.val) return a;
    return b;
}
int main()
{
    int n,x,sum = 0;
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)   scanf("%d",&x),++cnt[x],sum+=x,arr[i] = x;
    for(int i=1;i<=n;i++)
    {
        int mx = 0,from = 0;
        for(int j=1;j<=5000;j++)
        {
            for(int k=1;k<=50;k++)
            {
                if(!mark[arr[k]])   upd(1,n,j-arr[k],5000,1,cnt[arr[k]]),mark[arr[k]] = 1;
            }
            A a = query(1,n,1,j,1);
            dp[i][j] = a.val,path[i][j] = a.pos;
            for(int k=1;k<=50;k++)  mark[arr[k]] = 0;
        }
        build(1,n,1,i);
    }
    int now = n;
    ans[now] = path[now][sum];
    while(now)
    {
        sum-=path[now][sum],--now;
        ans[now] = path[now][sum];
    }
    for(int i=1;i<=n;i++)   printf("%d ",ans[i]);
    return 0;
}