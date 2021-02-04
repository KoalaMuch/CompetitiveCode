#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
map< long long,bool > mp;
int a[N];
long long qs[N];
int n;
void dvd(int l,int r)
{
    mp[qs[r]-qs[l-1]] = true;
    if(a[l]==a[r])    return;
    int mid = upper_bound(a+1,a+n+1,(a[l]+a[r])>>1)-a;
    dvd(l,mid-1);
    dvd(mid,r);
}
int main()
{
    int t,q,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)   qs[i] = qs[i-1]+a[i];
        dvd(1,n);
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&x);
            printf( mp[x] ? "Yes\n" : "No\n");
        }
        mp.clear();
    }
    return 0;
}
