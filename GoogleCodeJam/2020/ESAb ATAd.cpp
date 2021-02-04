#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int mark[N];
int overlap(int s,int e)    {return s>e;}
struct A
{
    int s,e,i;
    bool operator<(const A&o)const
    {
        return s<o.s;
    }
};
A a[N];
void solve()
{
    int n;
    memset(mark,-1,sizeof mark);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d %d",&a[i].s,&a[i].e),a[i].i = i;
    sort(a+1,a+n+1);
    for(int i=1,lst = 0;i<=n;i++)
    {
        if(!overlap(lst,a[i].s))    mark[a[i].i] = 0,lst = a[i].e;
    }
    for(int i=1,lst = 0;i<=n;i++)
    {
        if(mark[a[i].i]==-1&&!overlap(lst,a[i].s))  mark[a[i].i] = 1,lst = a[i].e;
    }
    int ch = 0;
    for(int i=1;i<=n;i++)   ch|=mark[i] == -1;
    if(ch)  printf("IMPOSSIBLE\n");
    else
    {
        for(int i=1;i<=n;i++)   printf(mark[i] ? "J" : "C");
        printf("\n");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}

