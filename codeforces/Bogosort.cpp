#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=n;i>=1;i--)   printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
