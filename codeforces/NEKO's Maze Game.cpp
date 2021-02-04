#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int sm[N*4];
bool a[2][N];
void upd(int l,int r,int idx,int now,int v)
{
    if(l>idx||r<idx||!idx)  return ;
    if(l==r)    {sm[now]=v;return;}
    int mid = (l+r) >> 1;
    upd(l,mid,idx,now<<1,v),upd(mid+1,r,idx,now<<1|1,v);
    sm[now] = sm[now<<1]|sm[now<<1|1];
}
void check(int i,int n)
{
    if(i>n) return ;
    int v = 0;
    if(a[0][i]&&a[1][i])    v = 1;
    if(a[0][i]&&(a[1][i+1]||a[1][i-1])) v = 1;
    if(a[1][i]&&(a[0][i+1]||a[0][i-1])) v = 1;
    upd(1,n,i,1,v);
}
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        --x;
        if(!a[x][y])    a[x][y] = true;
        else            a[x][y] = false;
        check(y-1,n),check(y,n),check(y+1,n);
        printf(sm[1] ? "No\n" : "Yes\n");
    }
    return 0;
}
