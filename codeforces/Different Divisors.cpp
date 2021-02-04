#include<bits/stdc++.h>
using namespace std;
const int N = 30005;
bool isprime[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    for(int i=2;i<N;i++)
    {
        if(isprime[i])  continue;
        for(int j=i+i;j<N;j+=i)
        {
            isprime[j] = true;
        }
    }
    while(q--)
    {
        long long f,s;
        scanf("%d",&n);
        for(int i=2;i<=30000;i++)
        {
            if(!isprime[i] && i-1>=n)    {f=i;break;}
        }
        for(int i=f;i<=30000;i++)
        {
            if(!isprime[i] && i-f>=n)    {s=i;break;}
        }
        printf("%lld\n",f*s);
    }
    return 0;
}
