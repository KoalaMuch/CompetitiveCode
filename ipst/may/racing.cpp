#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int lud[N];
int v[N];
int pos[N];
struct A
{
    int d,v,id,lud;
    bool operator<(const A&o)const
    {
        if(v!=o.v)  return  v<o.v;
        return d<o.d;
    }
};
priority_queue< A > sm[N*4];
struct B
{
    int v,a,b,T,pos;
    bool operator<(const B&o)const
    {
        if(T!=o.T)  return T<o.T;
        if(pos!=o.pos)  return pos<o.pos;
        return v<o.v;
    }
};
B opr[N*2];
void build(int l,int r,int now)
{
    for(int i=l;i<=r;i++)   sm[now].push({0,v[i],i,0});
    if(l!=r)
    {
        int mid = (l+r) >> 1;
        build(l,mid,now<<1),build(mid+1,r,now<<1|1);
    }
}
int n;
void PUSH(int l,int r,int idx,int now)
{
    sm[now].push({pos[idx],v[idx],idx,lud[idx]});
    if(l==r)    return;
    int mid = (l+r) >> 1;
    if(idx<=mid)    PUSH(l,mid,idx,now<<1);
    else            PUSH(mid+1,r,idx,now<<1|1);
}
void upd(int l,int r,int ll,int rr,int now,int upv,int upx,int upt)
{
    if(l>rr||r<ll)  return ;
    if(l>=ll&&r<=rr)
    {
        while(!sm[now].empty())
        {
            int nowd = sm[now].top().d,nowv=sm[now].top().v,nowid = sm[now].top().id,nowlud = sm[now].top().lud;
            sm[now].pop();
            if(lud[nowid]!=nowlud)  {continue;}
            if(nowv>upv&&(upt-nowlud)*nowv+nowd<=upx)
            {
                if(upv==0)
                {
                    lud[nowid] = upt;
                    pos[nowid] = upx;
                    v[nowid] = 0;
                }
                else
                {
                    lud[nowid] = upt;
                    pos[nowid] = (upt-nowlud)*nowv+nowd;
                    v[nowid] = upv;
                }
                PUSH(1,n,nowid,1);
            }
            else    {sm[now].push({nowd,nowv,nowid,nowlud});break;}
        }
        return ;
    }
    int mid = (l+r) >> 1;
    upd(l,mid,ll,rr,now<<1,upv,upx,upt),upd(mid+1,r,ll,rr,now<<1|1,upv,upx,upt);
}
int main()
{
    int m,T,A,B,V;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   scanf("%d",&v[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1) scanf("%d %d %d %d",&T,&A,&B,&V),++A,++B,--T,opr[i] = {0,A,B,T,V};
        else        scanf("%d %d %d %d",&T,&A,&B,&V),++A,++B,--T,opr[i] = {V,A,B,T,500000000};
    }
    sort(opr+1,opr+m+1);
    for(int i=1;i<=m;i++)   upd(1,n,opr[i].a,opr[i].b,1,opr[i].v,opr[i].pos,opr[i].T);
    while(!sm[1].empty())
    {
        int nowd = sm[1].top().d,nowv=sm[1].top().v,nowid = sm[1].top().id,nowlud = sm[1].top().lud;
        sm[1].pop();
        if(lud[nowid]!=nowlud)  {continue;}
        pos[nowid] = (100000000-nowlud)*nowv+nowd;
    }
    for(int i=1;i<=n;i++)   printf("%d\n",pos[i]);
    return 0;
}
/*
3 3
1 3 4
1 11 0 0 20
1 11 1 2 30
2 41 0 2 3


3 1
1 3 4
2 41 0 2 3

1 2
1
1 11 0 0 20
1 11 0 0 30
*/
