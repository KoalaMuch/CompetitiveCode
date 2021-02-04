#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2505;
pair< long long,long long > p[N];
int main()
{
    long long n,ans = 0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld %lld",&p[i].x,&p[i].y);
    for(long long i=1;i<=n;i++)
    {
        long long s1,s2,s3,s4,s12,s23,s34,s41;
        s1 = s2 = s3 = s4 = s12 = s23 = s34 = s41 = 0;
        for(long long j=1;j<=n;j++)
        {
            if(i==j)    continue;
            if(p[j].x>=p[i].x&&p[j].y>=p[i].y)  ++s1;
            if(p[j].x<=p[i].x&&p[j].y>=p[i].y)  ++s2;
            if(p[j].x<=p[i].x&&p[j].y<=p[i].y)  ++s3;
            if(p[j].x>=p[i].x&&p[j].y<=p[i].y)  ++s4;
            if(p[j].x==p[i].x&&p[j].y>p[i].y)   ++s12;
            if(p[j].y==p[i].y&&p[j].x<p[i].x)   ++s23;
            if(p[j].x==p[i].x&&p[j].y<p[i].y)   ++s34;
            if(p[j].y==p[i].y&&p[j].x>p[i].x)   ++s41;
        }
        printf("%lld %lld %lld %lld %lld %lld %lld %lld ",s1,s2,s3,s4,s12,s23,s34,s41);
        ans+=s1*s2*s3*s4-s12*s3*s4-s23*s1*s4-s34*s1*s2-s41*s2*s3+s12*s34+s23*s41*s34+s34*s12+s41*s23;
        printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
