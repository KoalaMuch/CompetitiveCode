#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,l,r;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&l,&r);
        printf(l>=r/2+1 ? "YES\n" : "NO\n");
    }
    return 0;
}
