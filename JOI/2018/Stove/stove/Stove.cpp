#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int b[N];
int main()
{
    int n,k,ans;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    ans = a[n]+1-a[1];
    for(int i=1;i<n;i++)    b[i] = a[i]+1-a[i+1];
    sort(b+1,b+n);
    for(int i=1;i<k;i++)    ans+=b[i];
    printf("%d\n",ans);
    return 0;
}
