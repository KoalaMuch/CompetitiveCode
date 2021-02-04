#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
long long a[N][N];
long long h[N][N];
struct A
{
    long long v,h,cnt;
};
stack< A > st;
int main()
{
    long long n,m,s = 0,ans = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            h[i][j] = 1+(a[i][j]==a[i-1][j])*h[i-1][j];
        }
    }
    for(long long i=1;i<=n;i++)
    {
        while(!st.empty())  st.pop();
        s = 0;
        for(long long j=1;j<=m;j++)
        {
            long long cnt = 1;
            while(!st.empty()&&st.top().v!=a[i][j]) s-=st.top().h*st.top().cnt,st.pop();
            while(!st.empty()&&h[i][j]<=st.top().h) s-=st.top().h*st.top().cnt,cnt+=st.top().cnt,st.pop();
            st.push({a[i][j],h[i][j],cnt});
            s+=h[i][j]*cnt;
            ans+=s;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
