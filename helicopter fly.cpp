#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m)
{
    int G = __gcd(n,m);
    if(G!=1)    return solve(n/G,m/G)*G;
    return n+m-1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",solve(n,m));
    return 0;
}
