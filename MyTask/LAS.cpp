#include<bits/stdc++.h>
using namespace std;
vector< int > g[100005];
int main()
{
    int n,ans=0,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        g[a].push_back(i);
    }
    for(int i=1;i<=100000;i++) g[i].push_back(1e9);
    for(int i=1;i<=n;i++)
    {
        int nowpos = 0;
        for(int j=1;j<=n;j++)
        {
            if(j*i>100000)  break;
            nowpos = g[j*i][upper_bound(g[j*i].begin(),g[j*i].end(),nowpos)-g[j*i].begin()];
            if(nowpos==1e9)    break;
            ans = max(ans,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}
