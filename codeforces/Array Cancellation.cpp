#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long p = 0,m = 0,n,x;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        if(x>=0)    p+=x;
        else
        {
            if((-x)>p)    m+=-(x+p),p = 0;
            else          p+=x;
        }
    }
    printf("%lld\n",(p+m)/2);
}
int main()
{
    long long q;
    scanf("%lld",&q);
    while(q--)
    {
        solve();
    }
    return 0;
}
