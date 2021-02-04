#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&m);
        int s = 0;
        for(int i=1,x;i<=n;i++)   scanf("%d",&x),s+=x;
        printf("%d\n",min(m,s));
    }
    return 0;
}
