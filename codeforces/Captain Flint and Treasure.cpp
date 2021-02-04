#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< long long > seq;
stack< long long > st;
queue< long long > q;
long long a[N];
long long b[N];
long long dgin[N];
int main()
{
    long long n,ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        if(b[i]!=-1)    ++dgin[b[i]];
    }
    for(long long i=1;i<=n;i++)   if(!dgin[i])    q.push(i);
    while(!q.empty())
    {
        long long now = q.front();q.pop();
        ans+=a[now];
        if(b[now]!=-1)
        {
            if(a[now]>=0)   a[b[now]]+=a[now],seq.push_back(now);
            else            st.push(now);
            --dgin[b[now]];
            if(!dgin[b[now]])   q.push(b[now]);
        }
        else    seq.push_back(now);
    }
    while(!st.empty())    seq.push_back(st.top()),st.pop();
    printf("%lld\n",ans);
    for(auto &x:seq)    printf("%lld ",x);
    return 0;
}
