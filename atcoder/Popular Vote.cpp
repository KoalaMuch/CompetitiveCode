#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int n,m,s = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),s+=a[i];
    sort(a+1,a+n+1,greater< int >());
    printf(a[m]>=(s+4*m-1)/(4*m) ? "Yes\n" : "No\n");
    return 0;
}
