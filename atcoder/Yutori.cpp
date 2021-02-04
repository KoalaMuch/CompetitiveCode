#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
int l[N];
int r[N];
int a[N];
int main()
{
    int n,k,c,cnt = 0;
    scanf("%d %d %d %s",&n,&k,&c,s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='x')   continue;
        a[++cnt] = i;
        int idx = upper_bound(a+1,a+cnt+1,a[cnt]-c-1)-a-1;
        l[cnt] = l[idx]+1;
    }
    for(int i=cnt;i>=1;i--)
    {
        int idx = lower_bound(a+1,a+cnt+1,a[i]+c+1)-a;
        r[i] = r[idx]+1;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(l[i]+r[i]-1==k&&l[i]!=l[i-1]&&r[i]!=r[i+1])  printf("%d\n",a[i]);
    }
    return 0;
}
