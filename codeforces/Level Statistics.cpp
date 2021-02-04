#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int p[N];
int c[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int valid = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&p[i],&c[i]);
            valid|=(p[i]<p[i-1]);
            valid|=(p[i]==p[i-1]&&c[i]!=c[i-1]);
            valid|=(p[i]>p[i-1]&&c[i]<c[i-1]);
            valid|=(c[i]>p[i]);
        }
        printf(valid ? "NO\n" : "YES\n");
    }
    return 0;
}
