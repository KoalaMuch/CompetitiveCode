#include<bits/stdc++.h>
using namespace std;
vector< long long > v;
long long check(long long n,long long k)
{
    while(n%k==0)   n/=k;
    return n%k==1;
}
void cal(long long n,long long old)
{
    long long sq = sqrt(n);
    for(long long i=2;i<=sq;i++)
    {
        if(n%i==0)
        {
            if(check(old,i))  v.push_back(i);
            if(check(old,n/i))v.push_back(n/i);
        }
    }
    if(n!=1)    v.push_back(n);
}
int main()
{
    long long n;
    scanf("%lld",&n);
    cal(n,n),cal(n-1,n);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    printf("%d\n",v.size());
    return 0;
}
