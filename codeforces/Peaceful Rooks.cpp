#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int own[N];
int mark[N];
int nxt[N];
pair< int,int > rook[N];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&rook[i].first,&rook[i].second);
            own[rook[i].first] = i;
        }
        for(int i=1;i<=m;i++)   nxt[i] = own[rook[i].second];
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            int cnt = 0,cur = i;
            if(mark[i]||rook[i].first==rook[i].second) continue;
            bool cy = false;
            while(cur!=0)
            {
                if(mark[cur]==i)   {cy=true;break;}
                if(mark[cur]!=0&&mark[cur]) break;
                mark[cur] = i;
                cur = nxt[cur];
                ++cnt;
            }
            if(cy)  ans+=cnt+1;
            else    ans+=cnt;
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)   mark[i] = own[i] = nxt[i] = 0;
    }
    return 0;
}
