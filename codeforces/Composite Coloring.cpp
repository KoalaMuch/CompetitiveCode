#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector< int > factor[N];
int ans[N];
int a[N];
int col[N];
int prime[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=2;i<=1000;i++)    prime[i] = 1;
    for(int i=2;i<=1000;i++)
    {
        if(!prime[i])  continue;
        for(int j=i+i;j<=1000;j+=i)   prime[j] = 0;
    }
    while(T--)
    {
        int m = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=2;i<=1000;i++)
        {
            if(!prime[i])   continue;
            int ch = 0;
            for(int j=1;j<=n;j++)
            {
                if(!ans[j]&&__gcd(a[j],i)!=1)
                {
                    if(!ch) ++m,ch = 1;
                    ans[j] = m;
                }
            }
        }
        printf("%d\n",m);
        for(int i=1;i<=n;i++)   printf("%d ",ans[i]);
        memset(col,0,sizeof col);
        memset(ans,0,sizeof ans);
        memset(a,0,sizeof a);
    }
    return 0;
}
