#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long pos[N];
long long f[3][N]; //0 = ans[n],1 =  to left,2 = to right
long long a[N];
long long less[N];
long long ans[N];
void upd(long long i,long long v,long long p)
{
    while(i<N)  f[p][i]+=v,i+=i&-i;
}
long long query(long long i,int p,long long ret = 0)
{
    while(i)  ans+=f[p][i],i-=i&-i;
    return ret;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),pos[a[i]] = i;
    for(long long i=n;i>=1;i--)
    {
        ans[n]+=less[a[i]] = query(a[i],0);
        upd(1,1,0),upd(a[i],-1,0);
    }
    for(long long i=n-1;i>=1;i--)
    {
        ans[i] = ans[i+1]+min(query(pos[a[i]],1),query(pos[a[i]],2))-less[a[i]];
        upd(pos[a[i]],1,1) //to left
        upd(1,1,2),upd(pos[a[i]],-1,2) //to right
    }
    for(long long i=1;i<=n;i++)   printf("%lld ",ans[i]);
    return 0;
}