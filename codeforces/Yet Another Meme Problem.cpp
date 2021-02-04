#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long A,B,T;
    scanf("%lld",&T);
    while(T--)
    {
        long long ans = 0;
        scanf("%lld %lld",&A,&B);
        long long st = 9;
        while(st<=B)
        {
            ans+=A;
            st = st*10+9;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
