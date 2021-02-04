#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int sm[N*16];
int lz[N*16];
void upd(int l,int r,int ll,int rr,int now)
{
    if(lz[now])
    {
        sm[now] = 1;
        if(l!=r)    lz[now<<1]=1,lz[now<<1|1]=1;
        lz[now] = 0;
    }
    if(l>rr||r<ll)  return ;
    if(l>=ll&&r<=rr)
    {
        sm[now]=1;
        if(l!=r)    lz[now<<1] = 1,lz[now<<1|1] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    upd(l,mid,ll,rr,now<<1),upd(mid+1,r,ll,rr,now<<1|1);
    sm[now]|=sm[now<<1]|sm[now<<1|1];
}
int query(int l,int r,int ll,int rr,int now)
{
    if(lz[now])
    {
        sm[now] = 1;
        if(l!=r)    lz[now<<1]=1,lz[now<<1|1]=1;
        lz[now] = 0;
    }
    if(l>rr||r<ll)  return 0;
    if(l>=ll&&r<=rr)    return sm[now];
    int mid = (l+r) >> 1;
    return query(l,mid,ll,rr,now<<1)|query(mid+1,r,ll,rr,now<<1|1);
}
struct A
{
    int a,b,c,d;
    bool operator<(const A&o)const
    {
        return b>o.b;
    }
};
A arr[N];
priority_queue< A > q;
bool cmp(A a,A b)
{
    return a.a<b.a;
}
vector< int > v;
int main()
{
    int n,a,b,c,d;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        v.push_back(a),v.push_back(b),v.push_back(c),v.push_back(d);
        arr[i] = {a,b,c,d};
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)
    {
        arr[i].a = lower_bound(v.begin(),v.end(),arr[i].a)-v.begin()+1;
        arr[i].b = lower_bound(v.begin(),v.end(),arr[i].b)-v.begin()+1;
        arr[i].c = lower_bound(v.begin(),v.end(),arr[i].c)-v.begin()+1;
        arr[i].d = lower_bound(v.begin(),v.end(),arr[i].d)-v.begin()+1;
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&q.top().b<arr[i].a)    upd(1,4*n,q.top().c,q.top().d,1),q.pop();
        if(query(1,4*n,arr[i].c,arr[i].d,1))  return puts("NO"),0;
        q.push({arr[i].a,arr[i].b,arr[i].c,arr[i].d});
        swap(arr[i].c,arr[i].a);
        swap(arr[i].d,arr[i].b);
    }
    memset(sm,0,sizeof sm),memset(lz,0,sizeof lz);
    while(!q.empty())   q.pop();
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&q.top().b<arr[i].a)    upd(1,4*n,q.top().c,q.top().d,1),q.pop();
        if(query(1,4*n,arr[i].c,arr[i].d,1))  return puts("NO"),0;
        q.push({arr[i].a,arr[i].b,arr[i].c,arr[i].d});
    }
    puts("YES");
    return 0;
}
