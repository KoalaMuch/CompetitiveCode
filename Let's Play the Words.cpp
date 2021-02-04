#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char str[N];
vector< int > v[2][2];
map< string ,int > mp; 
bool mk[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %s",str);
            int len = strlen(str);
            int f = str[0]-'0',s = str[len-1]-'0';
            v[f][s].push_back(i);
            
            if(mp[str]) mk[i] = mk[mp[str]] = true;
            reverse(str,str+len);
            mp[str] = i;
        }
        int a = v[0][0].size(),b = v[0][1].size(),c = v[1][0].size(),d = v[1][1].size();
        int ans = min(abs(b-(b+c)/2),abs(c-(b+c)/2));
        if(a&&d&&!(b||c))   printf("-1");
        else
        {
            printf("%d\n",ans);
            if(c>b) 
            {
                for(int i=0;ans;i++)
                {
                    if(mk[v[1][0][i]])  continue;
                    printf("%d ",v[1][0][i]);
                    --ans;
                }
            }   
            else
            {
                for(int i=0;ans;i++)
                {
                    if(mk[v[0][1][i]])  continue;
                    printf("%d ",v[0][1][i]);
                    --ans;
                }
            }    
        }
        printf("\n");
        for(int i=1;i<=n;i++)   mk[i] = false;
        for(int i=0;i<=1;i++)   for(int j=0;j<=1;j++)   v[i][j].clear();
        mp.clear();
    }
    return 0;
}