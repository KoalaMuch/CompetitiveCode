#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        if(i*(n/i)==n)  return !printf("%d%d",i,n/i);
    }
    return 0;
}
