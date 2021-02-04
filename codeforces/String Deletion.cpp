#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int v[N];
char s[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int id = 0,ans = 0;
        scanf("%d %s",&n,s+1);
        for(int i=1;i<=n;i++)
        {
            int cur = 1;
            while(s[i+1]==s[i]&&i+1<=n) ++cur,++i;
            v[++id] = cur;
        }
        int cur = 1;
        while(v[cur]==1&&cur<=id)    ++cur;
        for(int i=1;i<=id;i++)
        {
            if(v[i]>1)  ++ans;
            else
            {
                cur = max(cur,i+1);
                while(v[cur]==1&&cur<=id)   ++cur;
                if(cur!=id+1)   --v[cur];
                else            break;
                ++ans;
            }
            v[i] = 0;
        }
        int sum = 0;
        for(int i=1;i<=id;i++)  sum+=v[i];
        printf("%d\n",ans+(sum+1)/2);
    }
    return 0;
}
