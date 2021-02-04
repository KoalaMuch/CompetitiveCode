#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char str[N];
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int x = 0,ans = 0;
        scanf(" %s",str+1);
        n = strlen(str+1);
        for(int i=1;i<=n;i++)
        {
            int cnt = 0;
            while(str[i]=='1')    ++i,++cnt;
            a[++x] = cnt;
        }
        sort(a+1,a+x+1,greater<int>());
        for(int i=1;i<=x;i+=2)  ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}
