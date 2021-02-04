#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        if(n%2) n-=2,printf("7");
        for(int i=1;i<=n/2;i++) printf("1");
        printf("\n");
    }
    return 0;
}
