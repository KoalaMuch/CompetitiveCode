#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long pos[N],f[N],a[N],ls[N],ans[N],p[N],mn[N],mx[N],sz[N];
void upd(long long i,long long v){
    while(i<N)  f[i]+=v,i+=i&-i;
}
long long query(long long i,long long ret = 0){
    while(i)  ret+=f[i],i-=i&-i;
    return ret;
}
long long fin(long long i)
{
    if(p[i]==i) return i;
    return p[i] = fin(p[i]);
}
int main(){
    long long n,add = 0;    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)   scanf("%lld",&a[i]),pos[a[i]] = i,l[a[i]] = a[i-1],r[a[i-1]] = a[i],p[i] = mn[a[i]] = mx[a[i]] = i,sz[i] = 1;
    for(long long i=n;i>=1;i--){
        ans[n]+=ls[a[i]] = query(a[i]); upd(a[i],1);
    }
    for(long long i=n;i>=1;i--) ls[i] = ls[i]+ls[i+1];
    for(long long i=n;i>=1;i--){ 
        ans[i] = ans[n]-ls[i+1]+add;
        if(l[i])
        {
            long long rl = fin(l[i]);
            add = add-(sz[rl])*min(mn[rl]-1,n-mx[rl]);
            p[rl] = i;
            mn[i] = mn[rl];
            sz[i]+=sz[rl];
        }
        if(r[i])
        {
            long long rr = fin(r[i]);
            add = add-(sz[rr])*min(mn[rr]-1,n-mx[rr]);
            p[rr] = i;
            mx[i] = mx[rr];
            sz[i]+=sz[rr];
        }
        add = add+sz[i]*min(mn[i]-1,n-mn[r]);
    }
    for(long long i=1;i<=n;i++)   printf("%lld ",ans[i]);
    return 0;
}