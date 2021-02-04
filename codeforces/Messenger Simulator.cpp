#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int mn[N];
int mx[N];
int a[N];
int f[N];
int ff[N];
int nxt[N];
int lst[N];
int more[N];
void upd(int x,int v)
{
    while(x<N)  f[x]+=v,x+=x&-x;
}
int query(int x,int ret = 0)
{
    while(x)    ret+=f[x],x-=x&-x;
    return ret;
}
void upm(int x,int v)
{
    while(x<N)  more[x]+=v,x+=x&-x;
}
int finm(int x,int ret = 0)
{
    while(x)    ret+=more[x],x-=x&-x;
    return ret;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)   mn[i] = mx[i] = i,ff[i]=1e9;
    for(int i=1;i<=m;i++)   ff[a[i]]=min(ff[a[i]],i);
    for(int i=1;i<=m;i++)   if(ff[a[i]]==i) upd(i,1);
    for(int i=m;i>=1;i--)   nxt[i] = lst[a[i]],lst[a[i]]=i;
    for(int i=1;i<=m;i++)
    {
        mn[a[i]]=1;
        if(ff[a[i]]==i) mx[a[i]]=max(mx[a[i]],a[i]+finm(a[i])),upm(1,1),upm(a[i],-1);
        if(!nxt[i])
        {
            mx[a[i]] = max(mx[a[i]],query(m));
            upd(i,-1);
        }
        else
        {
            mx[a[i]] = max(mx[a[i]],query(nxt[i]));
            upd(i,-1),upd(nxt[i],1);
        }
    }
    for(int i=1;i<=n;i++)   if(ff[i]==1e9)   mx[i]+=finm(i);
    for(int i=1;i<=n;i++)   printf("%d %d\n",mn[i],mx[i]);
    return 0;
}
/*
10 20
10 1 5 7 1 2 5 3 6 3 9 4 3 4 9 6 8 4 9 6
*/
