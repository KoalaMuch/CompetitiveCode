#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",min(n%m,m-(n%m)));
    return 0;
}
