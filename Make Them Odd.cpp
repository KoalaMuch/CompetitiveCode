#include<bits/stdc++.h>
using namespace std;
map< int,int > mp;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int num;
            scanf("%d",&num);
            while(num%2==0&&!mp[num])   mp[num] = 1,num/=2,++ans;
        }
        printf("%d\n",ans);
        mp.clear();
    }
    return 0;
}