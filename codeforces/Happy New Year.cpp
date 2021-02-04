#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N*2][10];
vector< pair< int,int >  > v;
int cal(int a,int b)
{
    if(a==b)    return 0;
    return b-a-1;
}
int main()
{
    int n,k,m,s,e,i = 0,ans = 0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)   scanf("%d %d",&s,&e),v.push_back({s,1}),v.push_back({e+1,-1});
    sort(v.begin(),v.end());
    int lst1 = 0,lst2 = 0;
    for(int i=0;i<=2*n;i++) for(int j=1;j<=k;j++)   dp[i][j] = -2e9;
    int l1 = 0,l2 = 0;
    for(auto &x:v)
    {
        ++i;
        for(int j=0;j<=k;j++)
        {
            if(j+l2>=0)    dp[i][j+l2] = max(dp[i][j+l2],dp[i-1][j]+((j+l2)%2)*(x.first-l1));
            dp[i][j] = max(dp[i][j],dp[i-1][j]+(j%2)*(x.first-l1));
            ans = max(ans,dp[i][j]);
//            printf("%d %d %d\n",i,j,dp[i][j]);
        }
        l1 = x.first,l2 = x.second;
    }
    printf("%d\n",ans);
    return 0;
}
