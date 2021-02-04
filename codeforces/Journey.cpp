#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int l[N];
int r[N];
char s[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&n,s+1);
        for(int i=1;i<=n;i++)
        {
            l[i] = 1;
            if(s[i]!=s[i-1])    l[i] += l[i-1];
        }
        for(int i=n;i>=1;i--)
        {
            r[i] = 1;
            if(s[i]!=s[i+1])    r[i] += r[i+1];
        }
        for(int i=0;i<=n;i++)
        {
            int v = 1;
            if(s[i+1]=='R')   v+=r[i+1];
            if(s[i]=='L')     v+=l[i];
            printf("%d ",v);
        }
        for(int i=0;i<=n;i++)   l[i] = r[i] = 0;
        printf("\n");
    }
    return 0;
}
