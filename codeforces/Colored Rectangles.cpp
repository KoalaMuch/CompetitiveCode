#include<bits/stdc++.h>
using namespace std;
const int N = 202;
int dp[N][N][N];
int a[N];
int b[N];
int c[N];
int play(int R,int G,int B)
{
    if(dp[R][G][B]!=-1)  return dp[R][G][B];
    if(R+G+B<=1)    return dp[R][G][B] = 0;
    int mx = 0;
    if(R>=1&&G>=1)  mx = max(mx,play(R-1,G-1,B)+a[R]*b[G]);
    if(R>=1&&B>=1)  mx = max(mx,play(R-1,G,B-1)+a[R]*c[B]);
    if(G>=1&&B>=1)  mx = max(mx,play(R,G-1,B-1)+b[G]*c[B]);
    return dp[R][G][B] = mx;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int R,G,B;
    scanf("%d %d %d",&R,&G,&B);
    for(int i=1;i<=R;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=G;i++)   scanf("%d",&b[i]);
    for(int i=1;i<=B;i++)   scanf("%d",&c[i]);
    sort(a+1,a+R+1);
    sort(b+1,b+G+1);
    sort(c+1,c+B+1);
    printf("%d\n",play(R,G,B));
    return 0;
}
