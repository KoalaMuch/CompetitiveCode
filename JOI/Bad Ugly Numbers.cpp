#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)    {printf("-1\n");continue;}
        printf("2");
        for(int i=1;i<n;i++)    printf("3");
        printf("\n");
    }
    return 0;
}
