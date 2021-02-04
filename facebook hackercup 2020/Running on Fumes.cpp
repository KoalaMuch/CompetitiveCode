#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
deque< int > dq;
long long dp[N];
int main()
{
    freopen("running_on_fumes_chapter_1_input.txt","r",stdin);
    freopen("running_on_fumes_chapter_1_output.txt","w",stdout);
    int T,n,m,c;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        long long ans = 1e18;
        scanf("%d %d",&n,&m);
        m = min(n-1,m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c);
            if(i==1)    {dq.push_front(1);continue;}
            while(!dq.empty()&&i-dq.front()>m)    dq.pop_front();
            if(dq.empty()||!c)  dp[i] = -1;
            else                dp[i] = c+dp[dq.front()];
            while(!dq.empty()&&dp[i]!=-1&&dp[i]<=dp[dq.back()])   dq.pop_back();
            if(dp[i]!=-1)   dq.push_back(i);
        }
        for(int i=n-m;i<=n;i++) if(dp[i]!=-1)   ans = min(ans,dp[i]);
        if(ans==1e18)   ans = -1;
        printf("Case #%d: %lld\n",x,ans);
        while(!dq.empty())  dq.pop_back();
    }
    return 0;
}
