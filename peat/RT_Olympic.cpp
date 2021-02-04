#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,m,p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&p);
        if(m>=p)
            printf( n>=(p+1)*(m/p)+m-(m/p) ? "no\n" : "yes\n");
        else    printf(n==p ? "yes\n" : "no\n");
    }
    return 0;
}

