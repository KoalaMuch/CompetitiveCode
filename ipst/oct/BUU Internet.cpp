#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int m,n,l = 0,r = 0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),l = max(l,a[i]),r+=a[i];
    while(l<r)
    {
        int mid  = (l+r) >> 1;
        int cnt = 0,sum = 0;
        for(int i=1;i<=n;i++)
        {
            if(sum+a[i]>mid)
        }
        if(cnt>=m)  l=mid;
        else        r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
