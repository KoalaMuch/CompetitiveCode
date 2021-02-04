#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
vector< int > ans;
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a[0] = -1;
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==a[i-1])    ++cnt;
            else
            {
                if(a[i-1]==1&&cnt%2)    ans.pop_back();
                cnt = 1;
            }
            ans.push_back(a[i]);
        }
        if(a[n]==1&&cnt%2)  ans.pop_back();
        printf("%d\n",ans.size());
        for(auto &x:ans)    printf("%d ",x);
        printf("\n");
        ans.clear();
    }
    return 0;
}
/*
1 1 1 0 0 0
*/
