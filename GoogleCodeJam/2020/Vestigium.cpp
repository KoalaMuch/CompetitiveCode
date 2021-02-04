#include<bits/stdc++.h>
using namespace std;
const int N = 104;
int cnt[N];
int a[N][N];
void solve()
{
    int n,k = 0,r = 0,c = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   scanf("%d",&a[i][j]),k = k+a[i][j]*(i==j);
    for(int i=1;i<=n;i++)
    {
        int ch = 0;
        for(int j=1;j<=n;j++)
        {
            if(cnt[a[i][j]])    ch = 1;
            ++cnt[a[i][j]];
        }
        memset(cnt,0,sizeof cnt);
        r+=ch;
        ch = 0;
        for(int j=1;j<=n;j++)
        {
            if(cnt[a[j][i]])    ch = 1;
            ++cnt[a[j][i]];
        }
        memset(cnt,0,sizeof cnt);
        c+=ch;
    }
    printf("%d %d %d\n",k,r,c);
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
