#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int pos = 0,neg = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>=0)
            {
                pos+=a[i];
            }
            else
            {
                neg+=-a[i];
            }
        }
        if(neg>pos) sort(a+1,a+n+1);
        else        sort(a+1,a+n+1,greater<int>());
        if(pos==neg)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for(int i=1;i<=n;i++)
            {
                printf("%d ",a[i]);
            }
        }
    }
    return 0;
}