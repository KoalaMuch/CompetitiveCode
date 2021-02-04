#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=9;i++)
        {
            int a = i;
            for(int j=1;j<=9&&a<=n;j++,ans++,a = a*10+i);
        }
        printf("%d\n",ans);
    }
    return 0;
}