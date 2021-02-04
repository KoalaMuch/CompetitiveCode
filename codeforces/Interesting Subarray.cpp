#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int ch = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i-1&&!ch&&abs(a[i]-a[i-1])>=2)    ch=1,printf("YES\n%d %d\n",i-1,i);
        }
        if(!ch) printf("NO\n");
    }
    return 0;
}
