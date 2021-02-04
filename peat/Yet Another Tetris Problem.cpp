#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        bool odd = false,even = false;
        for(int i=1,x;i<=n;i++)
        {
            scanf("%d",&x);
            if(x%2) odd = true;
            else    even = true;
        }
        printf(odd&even ? "NO\n" : "YES\n");
    }
    return 0;
}
