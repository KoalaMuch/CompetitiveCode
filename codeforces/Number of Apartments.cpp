#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        if(n==1||n==2||n==4)
        {
            printf("-1\n");
        }
        else
        {
            if(n%3==2)  printf("%d %d %d\n",(n-5)/3,1,0);
            else if(n%3==1) printf("%d %d %d\n",(n-7)/3,0,1);
            else            printf("%d %d %d\n",n/3,0,0);
        }
    }
    return 0;
}
