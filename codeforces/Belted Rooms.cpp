#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
char s[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int ch = 0;
        int cnt = 0;
        scanf("%d %s",&n,s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='<')   ch|=1;
            else if(s[i]=='>')  ch|=2;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-'||s[(i-1+n)%n]=='-')  ++cnt;
        }
        if(ch!=3)  printf("%d\n",n);
        else    printf("%d\n",cnt);
    }
    return 0;
}
