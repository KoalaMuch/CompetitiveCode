#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
map< int,int > mp;
char a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        long long ans = 0;
        mp[0] = 1;
        int qs = 0;
        scanf("%d %s",&n,a+1);
        for(int i=1;i<=n;i++)
        {
            int now = a[i]-'0';
            qs+=now;
            ans+=mp[qs-i];
            ++mp[qs-i];
        }
        printf("%lld\n",ans);
        mp.clear();
    }
    return 0;
}
