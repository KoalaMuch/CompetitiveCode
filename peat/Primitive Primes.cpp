#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p,a = -1,b = -1;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=0,x;i<n;i++)
    {
        scanf("%d",&x);
        if(x%p&&a==-1)  a=i;
    }
    for(int i=0,x;i<m;i++)
    {
        scanf("%d",&x);
        if(x%p&&b==-1)  b=i;
    }
    printf("%d\n",a+b);
    return 0;
}
