#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
bool use[N];
int a[N];
int b[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int g = 0;
        for(int i=1;i<=n;i++)
        {
            int mx = 0,now = 0;
            for(int j=n;j>=1;j--)
            {
                if(__gcd(g,a[j])>mx&&!use[j])   mx = __gcd(g,a[j]),now = j;
            }
            g = __gcd(g,a[now]);
            b[i] = a[now];
            use[now] = true;
        }
        for(int i=1;i<=n;i++)   use[i] = false;
        for(int i=1;i<=n;i++)   printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}
