#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string a = "peatror";
char s[N];
int dp[N][7];
int main()
{
    printf("%d %d\n",1^1,0^1);
    int n;
    scanf(" %s",s+1);
    n = strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0]+(s[i]=='p');
        for(int j=1;j<7;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(s[i]==a[j])  dp[i][j] = (dp[i][j]+dp[i-1][j-1])%2555;
        }
    }
    printf("%d\n",dp[n][6]);

    return 0;
}
