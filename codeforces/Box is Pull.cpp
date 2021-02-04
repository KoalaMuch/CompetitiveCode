#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,a,b,c,d;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        printf("%d\n",abs(a-c)+abs(b-d)+2*(a!=c&&b!=d));
    }
    return 0;
}
