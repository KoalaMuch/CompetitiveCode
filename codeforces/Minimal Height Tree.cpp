#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
set< int > s[N];
int main()
{
    int q,n,x;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 0;
        scanf("%d",&n);
        scanf("%d",&x);
        s[0].insert(1);
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&x);
            int l = 0,r = ans;
            while(l<r)
            {
                int mid = (l+r)/2;
                if(*s[mid].begin()< x)    r = mid;
                else                      l = mid+1;
            }
            ans = max(ans,l+1);
            auto k = s[l].lower_bound(x);
            --k;
            s[l].erase(*k);
            s[l].insert(x);
            s[l+1].insert(0);
        }
        for(int i=0;i<=n-1;i++) s[i].clear();
        printf("%d\n",ans);
    }
    return 0;
}
