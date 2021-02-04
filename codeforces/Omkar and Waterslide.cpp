#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int b[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        long long ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]<a[i-1]) ans+=a[i-1]-a[i],b[i] = b[i-1];
            else            b[i] = a[i]+b[i-1]-a[i-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
