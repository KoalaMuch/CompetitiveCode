#include<bits/stdc++.h>
using namespace std;
int cnt[100];
int main()
{
    int q,n,x;
    scanf("%d",&q);
    while(q--)
    {
        long long ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            x = int(log2(x));
            ans+=cnt[x];
            ++cnt[x];
        }
        printf("%lld\n",ans);
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}
