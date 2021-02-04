#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        if(n<31)    printf("No\n");
        else if(n==36)  printf("YES\n5 6 10 15\n");
        else if(n==40)  printf("YES\n1 10 14 15\n");
        else if(n==44)  printf("YES\n6 7 10 21\n");
        else            printf("YES\n6 10 14 %d\n",n-30);
    }
    return 0;
}
