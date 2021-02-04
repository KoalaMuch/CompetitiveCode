#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long l[N];
long long r[N];
long long a[N];
struct A
{
    long long v,s,cnt,idx;
};
stack< A > st;
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]);
    st.push({0,0,0,0});
    for(long long i=1;i<=n;i++)
    {
        long long s = a[i],cnt = 1;
        while(!st.empty()&&a[i]<st.top().v)    s+=st.top().s,cnt+=st.top().cnt,st.pop();
        l[i] = s-(cnt*a[i])+l[st.top().idx];
        st.push({a[i],s,cnt,i});
    }
    while(!st.empty())  st.pop();
    st.push({0,0,0,0});
    for(long long i=n;i>=1;i--)
    {
        long long s = a[i],cnt = 1;
        while(!st.empty()&&a[i]<st.top().v)    s+=st.top().s,cnt+=st.top().cnt,st.pop();
        r[i] = s-(cnt*a[i])+r[st.top().idx];
        st.push({a[i],s,cnt,i});
    }
    long long id=1;
    for(long long i=2;i<=n;i++)
    {
        if(l[i]+r[i]<l[id]+r[id])    id = i;
    }
    for(long long i=id-1;i>=1;i--)  a[i] = min(a[i],a[i+1]);
    for(long long i=id+1;i<=n;i++)  a[i] = min(a[i],a[i-1]);
    for(long long i=1;i<=n;i++)   printf("%lld ",a[i]);
    return 0;
}
/*
5
5 1 4 3 2
*/
