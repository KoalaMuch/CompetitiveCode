#include<bits/stdc++.h>
using namespace std;
const int N = 5105;
int ans[N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if(n<=2&&m) return puts("-1"),0;
    ans[1] = 1,ans[2] = 2;
    for(int i=3;i<=n;i++)
    {
        if(!m)
        {
            int run = 0;
            for(int j=n;j>=i;j--)
            {
                ans[j] = 1e9-i*run++;
            }
            break;
        }
        else if((i-1)/2>m)
        {
            ans[i] = i-1+(i-1-2*m+1);
            m=0;
        }
        else    ans[i] = i,m-=(i-1)/2;
    }
    if(m)   return puts("-1"),0;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
