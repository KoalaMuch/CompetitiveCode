#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %s",s+1);
        int n = strlen(s+1),l = 0,mx = 0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='R')   mx = max(mx,i-l),l = i;
        }
        mx =  max(mx,n+1-l);
        printf("%d\n",mx);
    }
    return 0;
}
