#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char s[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int cnt1 = 0,ans1 = 0,cnt2 = 0,ans2 = 0;
        scanf("%d %s",&n,s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')   ++cnt1,ans2+=max(cnt2-1,0),cnt2 = 0;
            else            ++cnt2,ans1+=max(cnt1-1,0),cnt1 = 0;
        }
        ans1+=max(cnt1-1,0);
        ans2+=max(cnt2-1,0);
        printf("%d\n",max(ans1,ans2));
    }
    return 0;
}
