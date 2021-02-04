#include<bits/stdc++.h>
using namespace std;
int a[1<<20];
int ans = 0;
void dfs(int now)
{
    if(!a[now<<1]&&!a[now<<1|1])    a[now] = 0;
    else
    {
        if(a[now<<1]>a[now<<1|1])
        {
            a[now] = a[now<<1];
            dfs(now<<1);
        }
        else
        {
            a[now] = a[now<<1|1];
            dfs(now<<1|1);
        }
    }
}
int getsum(int now)
{
    int sum = a[now];
    a[now] = 0;
    if(a[now<<1])   sum+=getsum(now<<1);
    if(a[now<<1|1]) sum+=getsum(now<<1|1);
    return sum;
}
int main()
{
    int T,h,g;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&h,&g);
        int nh = (1<<h)-1,ng = (1<<g)-1;
        for(int i=1;i<=nh;i++)  scanf("%d",&a[i]);
        for(int i=1;i<=nh-ng;i++)   dfs(1);
        printf("%d\n",getsum(1));
        for(int i=1;i<=nh-ng;i++)   printf("1 ");
        printf("\n");
    }
    return 0;
}
