#include<bits/stdc++.h>
using namespace std;
map< int,int > mp;
int main()
{
    int q,n,s,k,x;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 1e9;
        scanf("%d %d %d",&n,&s,&k);
        for(int i=1;i<=k;i++)   scanf("%d",&x),mp[x]=1;
        for(int i=max(1,s-1001);i<=min(n,s+1001);i++)   if(!mp[i])  ans=min(ans,abs(i-s));
        printf("%d\n",ans);
        mp.clear();
    }
    return 0;
}
