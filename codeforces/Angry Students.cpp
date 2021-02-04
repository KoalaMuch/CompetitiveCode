#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char str[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int mx = 0,ch = 0,run;
        scanf("%d %s",&n,str+1);
        str[n+1] = '\0';
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='A') ch = 1,run=0;
            else if(str[i]=='P'&&ch)    ++run;
            else                        ch = 0;
            if(ch)  mx = max(mx,run);
        }
        printf("%d\n",mx);
    }
    return 0;
}
