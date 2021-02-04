#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        reverse(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
