#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
struct A
{
    long long a[2][2];
};
A sm[N*4];
int a[N];
void up(int l,int r,int now,int idx,int val)
{
    if(l>idx||r<idx)    return ;
    if(l==r)
    {
        sm[now].a[0][0] = val;
        sm[now].a[0][1] = sm[now].a[1][0] = -1e9;
        sm[now].a[1][1] = -val;
        return ;
    }
    int mid = (l+r) >> 1;
    up(l,mid,now<<1,idx,val),up(mid+1,r,now<<1|1,idx,val);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            sm[now].a[i][j] = max(sm[now<<1].a[i][j],sm[now<<1|1].a[i][j]);
            for(int k=0;k<2;k++)
            {
                sm[now].a[i][j] = max(sm[now].a[i][j],sm[now<<1].a[i][k]+sm[now<<1|1].a[k^1][j]);
            }
        }
    }
}
int main()
{
    int t,q,n,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]),up(1,n,1,i,a[i]);
        printf("%lld\n",max(max(sm[1].a[0][0],sm[1].a[0][1]),max(sm[1].a[1][0],sm[1].a[1][1])));
        while(q--)
        {
            scanf("%d %d",&l,&r);
            up(1,n,1,l,a[r]);
            up(1,n,1,r,a[l]);
            swap(a[l],a[r]);
            printf("%lld\n",max(max(sm[1].a[0][0],sm[1].a[0][1]),max(sm[1].a[1][0],sm[1].a[1][1])));
        }
    }
    return 0;
}
