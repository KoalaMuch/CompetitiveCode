#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,n,k;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&k);
        printf(n%2!=k%2||k*k>n ? "NO\n" : "YES\n");
    }
    return 0;
}

