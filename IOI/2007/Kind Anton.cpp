#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool have[2][N];
int a[N];
int b[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)   scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            have[0][i] = have[0][i-1];
            have[1][i] = have[1][i-1];
            if(a[i]==-1)    have[0][i] = true;
            if(a[i]==1)     have[1][i] = true;
        }
        int ch = 0;
        for(int i=n;i>=1;i--)
        {
            if(a[i]==b[i])  continue;
            if(a[i]<b[i]&&have[1][i-1])   continue;
            if(a[i]>b[i]&&have[0][i-1])   continue;
            ch = 1;
        }
        printf(ch ? "NO\n" : "YES\n");
        for(int i=1;i<=n;i++)   have[1][i] = have[0][i] = false;
    }
    return 0;
}
