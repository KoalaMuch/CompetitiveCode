#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int nxt[N][27];
char s[N];
char t[N];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s %s",s+1,t+1);
        n = strlen(s+1),m = strlen(t+1);
        for(int i=n-1;i>=0;i--)
        {
            nxt[i][s[i+1]-'a'] = i+1;
            for(int j=0;j<=25;j++)  nxt[i][j] = nxt[i][j] ? nxt[i][j] : nxt[i+1][j];
        }
        int cur = 0,ans = 1,ch=0;
        for(int i=1;i<=m;i++)
        {
            if(!nxt[cur][t[i]-'a'])   cur=0,++ans;
            if(!cur&&!nxt[cur][t[i]-'a']) ch=1;
            cur = nxt[cur][t[i]-'a'];
        }
        for(int i=0;i<=n-1;i++) for(int j=0;j<=25;j++)  nxt[i][j] = 0;
        printf(ch ? "-1\n" : "%d\n",ans);
    }
    return 0;
}
