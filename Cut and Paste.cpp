#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
string s;
int main()
{
    long long q,x,n;
    scanf("%lld",&q);
    while(q--)
    {
        cin >> x >> s;;
        n = s.size();
        long long ch = n>=x;
        for(long long i=0;i<x;i++)
        {
            long long a = s[i]-'0';
            if(!ch) for(int k=1;k<=a-1;k++)  for(int j=i+1;j<n;j++)  s.push_back(s[j]);
            n = (a*n - (a-1) * (i+1)+mod)%mod;
            ch |= n>=x;
        }
        printf("%lld\n",n);
    }
    return 0;
}
