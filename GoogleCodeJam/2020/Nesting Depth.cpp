#include<bits/stdc++.h>
using namespace std;
const int N = 104;
string ans;
char s[N];
void solve()
{
    int cur = 0;
    scanf(" %s",s+1);
    int n = strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        int now = s[i]-'0';
        while(cur<now)  ans+='(',++cur;
        while(cur>now)  ans+=')',--cur;
        ans+=s[i];
    }
    while(cur!=0)   ans+=')',--cur;
    cout << ans << endl;
    ans.clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
