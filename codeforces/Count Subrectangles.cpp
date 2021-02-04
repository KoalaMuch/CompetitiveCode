#include<bits/stdc++.h>
using namespace std;
const int N = 40005;
int a[N];
int b[N];
vector< int > factor;
map< int,int > mp;
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int sq = sqrt(k);
    for(int i=1;i<=sq;i++)
    {
        if(k%i==0&&k/i!=i)
        {
            if(k/i<=n||k/i<=m)  factor.push_back(i),factor.push_back(k/i);
        }
        else if(k%i==0)     factor.push_back(i);
    }
    sort(factor.begin(),factor.end());
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)   scanf("%d",&b[i]);
    int s = 0;
    for(int i=1;i<=n;i++)
    {
        s = (a[i]==1) ? s+1 : 0;
        for(auto &x:factor)
        {
            if(x>s) break;
            ++mp[x];
        }
    }
    s = 0;
    long long ans = 0;
    for(int i=1;i<=m;i++)
    {
        s = (b[i]==1) ? s+1 : 0;
        for(auto &x:factor)
        {
            if(x>s) break;
            ans+=mp[k/x];
        }
    }
    printf("%lld\n",ans);
}
