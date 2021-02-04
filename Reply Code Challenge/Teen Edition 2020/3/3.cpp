#include<bits/stdc++.h>
using namespace std;
long long s[100005],p[100005],a[100005];
int main()
{
    freopen("in5.txt","r",stdin);
    freopen("out5.txt","w",stdout);
    long long l,r,mid,i,j,sum,tim,t,k,m,n;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld %lld %lld",&n,&k,&m);
        for(j=1;j<=n;j++)   scanf("%lld %lld",&p[j],&s[j]);
        l=1;r=1e15;sum=0;
        while(l<r){
            mid=(l+r)/2;
            sum=0;
            for(j=1;j<=n;j++){
                tim=mid;
                tim-=p[j];
                a[j]=-(tim/s[j]);
            }
            sort(a+1,a+1+n);
            for(j=1;j<=k;j++){
                sum+=(-a[j]);
                sum = min(sum,m);
            }
            if(sum>=m)  r=mid;
            else    l=mid+1;
        }
        printf("Case #%lld: %lld\n",i,l);
    }
    return 0;
}
