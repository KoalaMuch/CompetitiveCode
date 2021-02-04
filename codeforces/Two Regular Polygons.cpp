#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        printf(__gcd(n,m)==m ? "YES\n" :  "NO\n");
    }
    return 0;
}
