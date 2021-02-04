#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+5;
int a[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        if(a[1]+a[2]>a[n]) printf("-1\n");
        else               printf("%d %d %d\n",1,2,n);
    }
    return 0;
}
