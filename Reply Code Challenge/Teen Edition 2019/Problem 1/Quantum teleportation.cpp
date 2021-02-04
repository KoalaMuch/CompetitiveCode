#include<bits/stdc++.h>
#define mod 100003;
using namespace std;
const int N = 2005;
struct A
{
    int inx,iny,outx,outy;
    bool operator<(const A&o)const
    {
        if(inx!=o.inx)  return inx<o.inx;
        return iny<o.iny;
    }
};
A a[N];
int mark[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,n,m,x0,y0,k;
    scanf("%d",&T);
    for(int X=1;X<=T;X++)
    {
        int ans = 0;
        scanf("%d %d %d %d %d",&n,&m,&x0,&y0,&k);
        for(int i=1;i<=k;i++)   scanf("%d %d %d %d",&a[i].inx,&a[i].iny,&a[i].outx,&a[i].outy);
        sort(a+1,a+k+1);
        for(int i=1;i<=k;i++)
        {
            int mn = 1e9,id;
            for(int j=1;j<=k;j++)
            {
                if(mark[j]) continue;
                int v =abs(x0-a[j].inx)+abs(y0-a[j].iny);
                if(v<mn)    mn = v,id = j;
            }
            ans=(ans+mn)%mod;
            x0 = a[id].outx,y0 = a[id].outy;
            mark[id] = 1;
        }
        memset(mark,0,sizeof mark);
        printf("Case #%d: %d\n",X,ans);
    }
    return 0;
}
/*
2
3 3
1  1
3
0 0 1 2
0 2 2 0
2 2 1 0
3 3
1  1
3
0 0 1 2
0 2 2 0
2 2 1 0
*/
