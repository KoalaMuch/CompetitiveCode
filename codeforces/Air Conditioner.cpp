#include<bits/stdc++.h>
using namespace std;
pair< int,int > f(int a,int b,int c,int d)
{
    if(c<a) swap(a,c),swap(b,d);
    return {c,min(b,d)};
}
int main()
{
    int q,n,m,t,l,h;
    scanf("%d",&q);
    while(q--)
    {
        int ch = 0;
        scanf("%d %d",&n,&m);
        pair< int,int > now = {m,m};
        int lst = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&t,&l,&h);
            now = f(now.first-(t-lst),now.second+(t-lst),l,h);
            if(now.second<now.first)    ch = 1;
            lst = t;
        }
        printf(ch ? "NO\n" : "YES\n");
    }
    return 0;
}
