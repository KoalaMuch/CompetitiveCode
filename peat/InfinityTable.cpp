#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int c(int i)
{
    int ret = 0;
    while(i)
    {
        ret = ret*10+(i%10);
        i/=10;
    }
    return ret;
}
int main()
{
    int mx = 0;
    printf("---");
    for(int i=1;i<=1000000000;i++)
    {
        int num = i,cnt = 0;
        while(num<=1000000000)
        {
            ++cnt;
            num = num+c(num);
        }
        mx = max(mx,cnt);
    }
    printf("%d\n",mx);
    scanf("%d",&mx);
    return 0;
}
