#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            if(i*4>3*n) printf("8");
            else        printf("9");
        }
        printf("\n");
    }
    return 0;
}
