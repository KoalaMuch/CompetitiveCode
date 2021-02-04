#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool no1[N];
bool no2[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            for(int j=1;j<=p;j++)
            {
                int x;
                scanf("%d",&x);
                if(!no2[x]&&!no1[i]) no1[i] = no2[x] = true;
            }
        }
        int f1 = 0,f2 = 0;
        for(int i=1;i<=n&&!f1;i++)  if(!no1[i]) f1 = i;
        for(int i=1;i<=n&&!f2;i++)  if(!no2[i]) f2 = i;
        for(int i=1;i<=n;i++)   no1[i] = no2[i] = false;
        if(f1)  printf("IMPROVE\n%d %d\n",f1,f2);
        else    printf("OPTIMAL\n");
    }
    return 0;
}
