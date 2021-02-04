#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
stack< pair< int,int > > st1,st2;
int dp[N];
int a[N];
int main()
{
    int n;
    scanf("%d %d",&n,&a[1]);
    st1.push({1,a[1]});
    st2.push({1,a[1]});
    for(int i=2;i<=n;i++)
    {
        dp[i] = 1e9;
        scanf("%d",&a[i]);
        int mx = -1e9-1;
        while(!st1.empty()&&a[i]>=st1.top().second)
        {
            if(mx<a[i]) dp[i] = min(dp[i],1+dp[st1.top().first]);
            mx = max(mx,st1.top().second);
            st1.pop();
        }
        if(!st1.empty()&&mx<a[i]) dp[i] = min(dp[i],1+dp[st1.top().first]);
        int mn = 1e9+1;
        while(!st2.empty()&&a[i]<=st2.top().second)
        {
            if(mn>a[i]) dp[i] = min(dp[i],1+dp[st2.top().first]);
            mn = min(mn,st2.top().second);
            st2.pop();
        }
        if(!st2.empty()&&mn>a[i]) dp[i] = min(dp[i],1+dp[st2.top().first]);
        st1.push({i,a[i]});
        st2.push({i,a[i]});
        //printf("%d %d\n",i,dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}
/*
7
8 5 5 8 6 5 7
*/
