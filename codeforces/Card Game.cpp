#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,n,m;
    scanf("%d",&T);
    while(T--)
    {
        int ch = 0,x;
        scanf("%d %d %d",&N,&n,&m);
        for(int i=1;i<=n;i++)   scanf("%d",&x),ch|=x==N;
        for(int i=1;i<=m;i++)   scanf("%d",&x);
        printf(ch ? "YES\n" : "NO\n" );
    }
    return 0;
}
