#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct A
{
    int sz,v;
    bool operator<(const A&o)const
    {
        if(v!=o.v)    return v<o.v;
        return sz<o.sz;
    }
};
A a[N];
int b[N];
int dp[N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   scanf("%d %d",&a[i].sz,&a[i].v);
    for(int i=1;i<=m;i++)   scanf("%d",&b[i]);
    sort(a+1,a+n+1); sort(b+1,b+m+1);
    int l = n,r = m,ans = 0;
    while(l&&r)
    {
        if(a[l].sz<=b[r])   ++ans,--l,--r;
        else                --l;
    }
    printf("%d\n",ans);
    return 0;
}
/*
3 4
5 1
3 5
10 20
4 4 6 10

8 8
508917604 35617051
501958939 840246141
485338402 32896484
957730250 357542366
904165504 137209882
684085683 775621730
552953629 20004459
125090903 607302990
433255278
979756183
28423637
856448848
276518245
314201319
666094038
149542543
*/
