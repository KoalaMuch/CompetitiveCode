#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< pair< int,int > > v;
int a[N];
int cnt[N];
void Clear(int n)
{
    for(int i=1;i<=n;i++)   cnt[i] = 0;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int mx = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]),mx = max(mx,a[i]),++cnt[a[i]];
        int ch = 0;
        for(int i=1;i<=n-mx;i++)
        {
            if(i<=n-mx&&cnt[i]!=2)        ch = 1;
            else if(i>n-mx&&cnt[i]!=1)    ch = 1;
        }
        Clear(n);
        if(ch)  {printf("%d\n",0);continue;}
        ch = 0;
        for(int i=1;i<=mx;i++)
        {
            ++cnt[a[i]];
            if(cnt[a[i]]==2)    ch = 1;
        }
        if(!ch) v.push_back({mx,n-mx});
        Clear(n);
        ch = 0;
        for(int i=n-mx+1;i<=n;i++)
        {
            ++cnt[a[i]];
            if(cnt[a[i]]==2)    ch = 1;
        }
        if(!ch) v.push_back({n-mx,mx});
        v.resize(unique(v.begin(),v.end())-v.begin());
        printf("%d\n",v.size());
        for(auto &x:v)  printf("%d %d\n",x.first,x.second);
        Clear(n);
        v.clear();
    }
    return 0;
}

