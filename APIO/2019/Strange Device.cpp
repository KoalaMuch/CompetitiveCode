#include<bits/stdc++.h>
using namespace std;
vector< pair< long long,long long > > v;
int main()
{
    long long n,a,b,s,f,ans = 0,l,r;
    scanf("%lld %lld %lld",&n,&a,&b);
    a/=__gcd(a,b+1);
    if(a>1e18/b)    a = 1e18+1;
    else            a *=b;
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %lld",&l,&r);
        if(r-l+1>=a)            v.push_back({0,a-1});
        else if((r%a)<(l%a))    v.push_back({l%a,a-1}),v.push_back({0,r%a});
        else                    v.push_back({l%a,r%a});
    }
    sort(v.begin(),v.end());
    s = v[0].first,f = v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first>f)   ans+=f-s+1,tie(s,f) = v[i];
        else                f = max(f,v[i].second);
    }
    printf("%lld\n",ans+f-s+1);
    return 0;
}
/*
3 5 10
1 20
50 68
89 98

2 16 13
2 5
18 18

3 3 3
4 4
7 9
17 18
*/
