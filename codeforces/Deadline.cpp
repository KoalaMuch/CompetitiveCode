#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&d);
        int sq = sqrt(d),ch = 0;
        for(int i=0;i<=sq;i++)  if(i+ceil((double)d/(i+1))<=n)  ch = 1;
        printf( (ch) ? "YES\n" : "NO\n");
    }
    return 0;
}
