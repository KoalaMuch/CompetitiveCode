#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int dp[2][N];
int mx[2][N][2];
char s[2][N];
int path[6000005];
vector< pair< char,char > > v;
int con(char c)
{
    if(c=='R')  return 1;
    return 0;
}
int contab(int i,int j,int col)
{
    return (i-1)*col+j;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(-1,mx,sizeof mx);
    for(int i=1;i<=n;i++)
    {
        int curi = i%2;
        scanf(" %s",s[curi]+1);
        for(int j=1;j<=m;j++)
        {
            int now = con(s[curi][j]),a = -1,b = -1,c = -1,d = -1;
            //top
            if(mx[curi^1][j][now^1]!=-1)    a = 1+mx[curi^1][j][curi^1];
            b = dp[curi^1][j];
            if(mx[curi][j-1][now^1]!=-1)    c = 1+mx[curi][j-1][now^1]!=1;
            d = dp[curi][j-1];
            if(max(a,b)>max(c,d))   path[contab(i,j)] = contab(i-1,j),dp[curi][j] = max(a,b);
            else                    path[contab(i,j)] = contab(i,j-1),dp[curi][j] = max(c,d);
            mx[curi][j][0] = mx[curi^1][j][0];
            mx[curi][j][1] = mx[curi^1][j][1];
            mx[curi][j][now] = max(mx[curi][j][now],max(b,d))
            mx[curi^1][j][0] = mx[curi^1][j][1] = -1
            dp[curi^1][j] = 0;
        }
        int R = dp[n%2][m],C = dp[n%2][m];
        if(con(s[n%2][m])==1&&)
        while(R!=0||C!=0)
        {
            if()
        }
    }
    return 0;
}
