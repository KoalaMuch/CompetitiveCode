#include<bits/stdc++.h>
using namespace std;
const int N = 52;
int f[N][N];
char in[N];
char out[N];
int main()
{
    freopen("realin1.txt","r",stdin);
    freopen("realout1.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        printf("Case #%d:\n",x);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf(" %c",&in[i]);
        for(int i=1;i<=n;i++)   scanf(" %c",&out[i]);
        for(int i=1;i<=n;i++)   f[i][i+1] = out[i]=='Y'&&in[i+1]=='Y',f[i+1][i] = out[i+1]=='Y'&&in[i]=='Y',f[i][i] = 1;
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    f[i][j]|=f[i][k]&f[k][j];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            in[i] = out[i] = 0;
            for(int j=1;j<=n;j++)
            {
                printf(f[i][j] ? "Y" : "N");
                f[i][j] = 0;
            }
            printf("\n");
        }
    }
    return 0;
}
/*
1
10
NYYYNNYYYY
YYNYYNYYNY
*/
