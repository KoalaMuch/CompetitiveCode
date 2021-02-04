#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int main()
{
    int q,n,k;
    scanf("%d",&q);
    while(q--)
    {
        long long s = 0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=k+1;i++) s+=a[i];
        printf("%lld\n",s);
    }
    return 0;
}
