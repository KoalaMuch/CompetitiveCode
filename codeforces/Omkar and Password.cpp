#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf(a[1]!=a[n] ? "1\n" : "%d\n",n);
    }
    return 0;
}
