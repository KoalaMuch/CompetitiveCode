#include<bits/stdc++.h>
using namespace std;
const int N = 8e5+5;
pair< int,int > p[N];
map< int,int > mp;
int Max(int &a,int b)
{
    a = max(a,b);
    return a;
}
int main()
{
    freopen("timber_input.txt","r",stdin);
    freopen("timber_output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d %d",&p[i].first,&p[i].second);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)
        {
            Max(ans,Max(mp[p[i].first+p[i].second],mp[p[i].first]+p[i].second));
            Max(ans,Max(mp[p[i].first],mp[p[i].first-p[i].second]+p[i].second));
        }
        printf("Case #%d: %d\n",x,ans);
        mp.clear();
    }
    return 0;
}
