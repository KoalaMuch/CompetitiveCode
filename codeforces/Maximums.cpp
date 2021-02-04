#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx = 0,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        printf("%d ",mx+x);
        mx = max(mx,mx+x);
    }
    return 0;
}
