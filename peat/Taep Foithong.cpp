#include<bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N];
int p[11];
vector< int > g[4000005];
int dp[4000005];
queue< int > q;
int c(int i)
{
    int ret = 0;
    while(i)
    {
        ret+=p[i%10];
        i/=10;
    }
    return ret;
}
int main()
{
    int T,n,k;
    scanf("%d %d",&T,&k);
    for(int i=1;i<=9;i++)
    {
        p[i] = 1;
        for(int j=1;j<=k;j++)   p[i]*=i;
    }
    for(int i=4000000;i>=1;i--)
    {
        int now = c(i);
        if(now>4000000)    continue;
        if(now!=i)  g[now].push_back(i);
        else        dp[now] = 1,q.push(now);
    }
    while(!q.empty())
    {
        int now = q.front(); q.pop();
        for(auto &x:g[now])
        {
            if(!dp[x])  dp[x]=1,q.push(x);
        }
    }
    while(T--)
    {
        scanf(" %s",s+1);
        int tmp = 0;
        n = strlen(s+1);
        for(int i=1;i<=n;i++)
        {
            tmp+=p[s[i]-'0'];
        }
        while(tmp>3720087)  tmp = c(tmp);
        printf(dp[tmp] ? "Yes\n" : "No\n");
    }
    return 0;
}
