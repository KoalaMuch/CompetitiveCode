#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
int a[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        bool ok = false;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(i>1 && a[i]>=a[i-1]) ok = true;
        }
        printf(ok? "YES\n" : "NO\n");
    }
    return 0;
}
