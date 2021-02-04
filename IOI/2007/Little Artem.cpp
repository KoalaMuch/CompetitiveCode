#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf(i==n&&j==m ? "W" : "B");
            }
            printf("\n");
        }
    }
    return 0;
}
