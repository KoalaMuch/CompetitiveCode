#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,ans = 0;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    for(int i=0;i<=100000;i++)
    {
        if(min(a,d)<i)  break;
        ans = max(ans,e*i+f*min(d-i,min(b,c)));
    }
    printf("%d\n",ans);
    return 0;
}