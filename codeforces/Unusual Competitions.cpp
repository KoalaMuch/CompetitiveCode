#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char str[N];
int main()
{
    int n,s = 0,l = 0,ans = 0;
    bool ch = false;
    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;i++)
    {
        s = (str[i]=='(') ? s+1 : s-1;
        if(s==-1)           ch = true;
        else if(s==0&&ch)   ans+=l+1,ch = false,l = 0;
        if(ch)  ++l;
    }
    printf(s ? "-1\n" : "%d\n",ans);
    return 0;
}
