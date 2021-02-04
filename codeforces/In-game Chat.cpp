#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&n,s+1);
        int cnt = 0;
        for(int i=n;i>=1;i--)
        {
            if(s[i]!=')')   break;
            ++cnt;
        }
        printf(cnt>n-cnt ? "Yes\n" : "No\n");
    }
    return 0;
}
