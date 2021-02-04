#include<bits/stdc++.h>
using namespace std;
double dp[105];
int main()
{
    int n;
    double ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   ans+=(double)1/i;
    printf("%.12lf\n",ans);
    return 0;
}
