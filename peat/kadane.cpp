#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n,s=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        s+=a[i];
        s=max(s,0);
        ans = max(ans,s);
    }
    printf("%d\n",ans);
    return 0;
}
