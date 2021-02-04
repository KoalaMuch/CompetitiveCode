#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int main()
{
    int n,mx = 0,O = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),O|=a[i];
    for(int i=1;i<=n;i++)   mx = max(mx,a[i]^O);
    printf("%d\n",mx);
    return 0;
}
