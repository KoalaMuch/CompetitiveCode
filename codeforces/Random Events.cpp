#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main()
{
    int t,n,m,x;
    double y;
    scanf("%d",&t);
    while(t--)
    {
        double del = 1;
        scanf("%d %d",&n,&m);
        int sorted = n+1;
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)
        {
            if(a[i]!=i)
            {
                sorted = i;
                break;
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d %lf",&x,&y);
            if(x>=sorted)   del*=(1.0-y);
        }
        if(sorted==n+1)   {printf("1.000000\n");continue;}
        printf("%.6lf\n",1-del);
    }
    return 0;
}
