#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
vector< pair< int,int > > ans;
int lft[1000005];
int a[N];
void set_up(int n)
{
    for(int i=1;i<=2*n;i++) lft[a[i]]=0;
    for(int i=1;i<=2*n;i++) lft[a[i]]++;
}
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        bool ch = false;
        for(int i=1;i<=2*n-1;i++)
        {
            set_up(n);
            --lft[a[2*n]];
            --lft[a[i]];
            ans.push_back({a[2*n],a[i]});
            int lst = a[2*n];
            int cur = 2*n;
            for(int j=1;j<=n-1;j++)
            {
                while(lft[a[cur]]==0)   --cur;
                --lft[a[cur]];
                if(lft[lst-a[cur]]==0)  {break;}
                ans.push_back({a[cur],lst-a[cur]});
                --lft[lst-a[cur]];
                lst = a[cur];
            }
            if(ans.size()==n)
            {
                ch = true;
                printf("YES\n%d\n",ans[0].first+ans[0].second);
                for(int i=0;i<n;i++)    printf("%d %d\n",ans[i].first,ans[i].second);
                ans.clear();
                break;
            }
            else    ans.clear();
        }
        if(ch==false)   printf("NO\n");
        for(int i=1;i<=2*n;i++) lft[a[i]] = 0;
    }
    return 0;
}
