#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,l,r;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&l,&r);
        if(2*l>r)   printf("-1 -1\n");
        else        printf("%d %d\n",l,l*2);
    }
    return 0;
}
