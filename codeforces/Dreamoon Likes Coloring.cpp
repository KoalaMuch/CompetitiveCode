#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int ans[N];
int main()
{
    int n,m,s = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)   scanf("%d",&a[i]),s = min(n,s+a[i]);
    if(s<n)    return !printf("-1\n");
    for(int i=1;i<=m;i++)
    {
        if(a[i]+i-1>n) return !printf("-1\n");
        ans[i] = i;
    }
    int lst = n+1;
    for(int i=m;i>=1;i--)
    {
        if(ans[i]+a[i]<lst)    ans[i] = lst-a[i];
        lst = ans[i];
    }
    if(lst!=1) return !printf("-1\n");
    for(int i=1;i<=m;i++)   printf("%d ",ans[i]);
    return 0;
}
/*
6 3
4 4 4
*/
