#include<bits/stdc++.h>
using namespace std;
const int N = 65;
char a[2][N][N];
int P[N];
bool haver[N][N];
bool havel[N][N];
int solve(int r,int c,int t)
{
    int ans = 1e9;
    for(int i=1;i<=r;i++)
    {
        P[i] = 0;
        for(int j=1;j<=c;j++)
        {
            P[i] = P[i]+(a[t][i][j]=='P');
            if(a[t][i][j]=='P'||havel[i][j-1])  havel[i][j] = true;
        }
        for(int j=c;j>=1;j--)   if(a[t][i][j]=='P'||haver[i][j+1])    haver[i][j] = true;
        P[i] = P[i-1]+P[i];
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(a[t][i][j]=='A') ans = min(ans,4-(P[i-1]==0)-(P[r]-P[i]==0)-(havel[i][j-1]==false)-(haver[i][j+1]==false));
        }
    }
    for(int i=1;i<=r;i++)
    {
        P[i] = 0;
        for(int j=1;j<=c;j++)   havel[i][j] = haver[i][j] = false;
    }
    return ans;
}
int main()
{
    int q,r,c;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 1e9;
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++)
        {
            scanf(" %s",a[0][i]+1);
            for(int j=1;j<=c;j++)
            {
                a[1][j][i] = a[0][i][j];
            }
        }
        ans = min(solve(r,c,0),solve(c,r,1));
        printf(ans==1e9 ? "MORTAL\n" : "%d\n",ans);
    }
    return 0;
}