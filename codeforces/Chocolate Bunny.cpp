#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int ans[N];
bool found[N];
int main()
{
    int n,a,b;
    scanf("%d",&n);
    int now = 1;
    for(int i=2;i<=n;i++)
    {
        printf("? %d %d\n",now,i);
        fflush(stdout);
        scanf("%d",&a);
        printf("? %d %d\n",i,now);
        fflush(stdout);
        scanf("%d",&b);
        if(a<b)
        {
            ans[i] = b;
            found[b] = true;
        }
        else
        {
            ans[now] = a;
            now = i;
            found[b] = true;
        }
    }
    int miss;
    for(int i=1;i<=n;i++)   if(!found[i])   miss = i;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)   ans[i] = miss;
    }
    printf("! ");
    for(int i=1;i<=n;i++)   printf("%d ",ans[i]);
    return 0;
}
/*
3
? 1 2
1
? 2 1
0
? 2 3
1
? 3 2
2
*/
