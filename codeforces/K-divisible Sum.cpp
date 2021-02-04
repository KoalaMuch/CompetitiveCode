#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        k = k*((n+k-1)/k);
        printf("%d\n",k/n+(k%n!=0));
    }
    return 0;
}
