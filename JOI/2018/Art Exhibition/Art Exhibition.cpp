#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long qs[N];
pair< long long,long long > a[N];
int main()
{
    long long ans = 0,mx = -1e18,n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld %lld",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        qs[i] = a[i].second+qs[i-1];
        mx = max(mx,-qs[i-1]+a[i].first);
        ans = max(ans,mx+qs[i]-a[i].first);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
15
1543361732 260774320
2089759661 257198921
1555665663 389548466
4133306295 296394520
2596448427 301103944
1701413087 274491541
2347488426 912791996
2133012079 444074242
2659886224 656957044
1345396764 259870638
2671164286 233246973
2791812672 585862344
2996614635 91065315
971304780 488995617
1523452673 988137562
*/
