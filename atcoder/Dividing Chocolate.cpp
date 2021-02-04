#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int qs[12][N];
int dp[N];
char s[N];
int n,m,k;
int get(int i,int j,int k,int l)
{
    return qs[k][l]-qs[i-1][l]-qs[k][j-1]+qs[i-1][j-1];
}
int check(int bit,int st,int en)
{
    int last = 1;
    for(int j=1;j<=n;j++)
    {
        if((1<<(j-1))&bit)
        {
            if(get(last,st,j,en)>k) return 0;
            last = j+1;
        }
    }
//    if(bit==2&&st==1&&en==4)    printf("[[%d %d %d %d %d]]\n",get(st,last,n,en),st,last,n,en);
    if(get(last,st,n,en)>k)  return 0;
    return 1;
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    int lim = 1<<(n-1),ans = 1e9;
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",s+1);
        for(int j=1;j<=m;j++)
        {
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+(s[j]=='1');
        }
    }
    for(int i=0;i<lim;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int l = 0,r = j-1;
            dp[j] = 1e9;
            while(l<r)
            {
                int mid = (l+r) >> 1;
                if(check(i,mid+1,j))    r=mid;
                else                    l=mid+1;
            }
            if(check(i,l+1,j))  dp[j] = min(dp[j],dp[l]+(l!=0));
//            if(i==2)    printf("[%d %d %d %d]\n",j,dp[j],l,check(2,1,4));
        }
        ans = min(ans,dp[m]+__builtin_popcount(i));
    }
    printf("%d\n",ans);
    return 0;
}
