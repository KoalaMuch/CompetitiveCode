#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int v[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)   v[i] = 1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i+i;j<=n;j+=i)    v[j] = max(v[j],__gcd(j,i));
    }
    sort(v+2,v+n+1);
    for(int i=2;i<=n;i++)   printf("%d ",v[i]);
    return 0;
}
