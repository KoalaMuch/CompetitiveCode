#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int mn[N];
char s[N];
int main()
{
    int q,n,k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %s",&n,&k,s);
        for(int i=0;i<k;i++)    mn[i] = 1e9;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')   continue;
            int x = s[i]-'0';
            mn[i%k] = min(mn[i%k],x);
        }
        bool ch = true;
        for(int i=0;i<n;i++)
        {
            if(mn[i%k]!=1e9&&s[i]=='?') s[i] = mn[i%k]+'0';
            else if(mn[i%k]!=1e9&&s[i]!=mn[i%k]+'0')    ch = false;
        }
        int z = 0,o = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')   z++;
            if(s[i]=='1')   o++;
            if(i>=k&&s[i-k]=='0')   --z;
            if(i>=k&&s[i-k]=='1')   --o;
            if(i>=k-1&&max(z,o)>k/2)  ch = false;
        }
        printf(ch ? "YES\n" : "NO\n");
    }
    return 0;
}
