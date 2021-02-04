#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char str[N];
int main()
{
    int q,n,x;
    scanf("%d",&q);
    while(q--)
    {
        int s=0,now=0,ans=0;
        scanf("%d %d %s",&n,&x,str+1);
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='0') ++s;
            else            --s;
        }
        if(x==0)    ++ans;
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='0') ++now;
            else            --now;
            if(s&&(x-now)%s==0&&(x-now)/s>=0)    ++ans;
            else if(!s&&x-now==0)   ++ans;
        }
        if(s==0&&ans>=1)    printf("-1\n");
        else                printf("%d\n",ans);
    }
    return 0;
}
