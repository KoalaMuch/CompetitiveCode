#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            if(i%3==1)  printf("a");
            else if(i%3==2)        printf("b");
            else        printf("c");
        }
        printf("\n");

    }
    return 0;
}
