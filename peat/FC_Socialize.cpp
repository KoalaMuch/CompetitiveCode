#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1000;i<=1000;i++)
    {
        for(int j=1001;j<=1001;j++)
        {
            for(int k=1;k<=min(i,j);k++) if(i/k!=j/k)    printf("%d\n",k);
        }
    }
    return 0;
}
