#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        printf("2\n%d %d\n",n,n-1);
        for(int i=1;i<=n-2;i++)
        {
            printf("%d %d\n",n-i+1,n-i-1);
        }
    }
    return 0;
}
