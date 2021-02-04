#include<bits/stdc++.h>
using namespace std;
vector< char > ans;
int main()
{
    int n,m,k,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=2*k;i++)
    {
        scanf("%d %d",&x,&y);
    }
    for(int i=1;i<=n-1;i++)  ans.push_back('U');
    for(int i=1;i<=m-1;i++) ans.push_back('L');
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            if(i%2) ans.push_back('R');
            else    ans.push_back('L');
        }
        if(i!=n)    ans.push_back('D');
    }
    printf("%d\n",ans.size());
    for(auto &x:ans)    printf("%c",x);
    return 0;
}
