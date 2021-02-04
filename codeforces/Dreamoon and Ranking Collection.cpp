#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int mark[N*2];
int main()
{
    int T,n,x,num;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&x);
        for(int i=1;i<=n;i++)   scanf("%d",&num),mark[num] = 1;
        int ans = 0;
        for(int i=1;i<=205;i++)
        {
            if(!mark[i])    --x;
            if(x>=0)    ans = max(ans,i);
        }
        printf("%d\n",ans);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
