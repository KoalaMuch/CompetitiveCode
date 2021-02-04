#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< int > v[11];
char str[N];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",str+1);
        int n = strlen(str+1),mx = 0;
        for(int i=1;i<=n;i++)   v[str[i]-'0'].push_back(i);
        for(int i=0;i<=9;i++)   v[i].push_back(1e9);
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int turn = 0,cur = 0,cnt = 0;
                while(1)
                {
                    if(!turn)   cur = v[i][upper_bound(v[i].begin(),v[i].end(),cur)-v[i].begin()];
                    else        cur = v[j][upper_bound(v[j].begin(),v[j].end(),cur)-v[j].begin()];
                    if(cur<=n)  ++cnt;
                    else        break;
                    turn^=1;
                }
                if(i!=j&&cnt%2) --cnt;
                mx = max(mx,cnt);
            }
        }
        printf("%d\n",n-mx);
        for(int i=0;i<=9;i++)   v[i].clear();
    }
    return 0;
}
