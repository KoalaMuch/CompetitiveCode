#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
pair< int,int >  must[N];
pair< int,int >  edge[N];
int p[N];
int fin(int i)  {return p[i]==i  ? i : p[i] = fin(p[i]);}
int main()
{
    int T,n,w,m,run = 0;
    scanf("%d",&T);
    while(T--)
    {
        ++run;
        scanf("%d %d %d",&n,&m,&w);
        for(int i=1;i<=w;i++)   scanf("%d %d",&must[i].first,&must[i].second);
        for(int i=1;i<=m;i++)   scanf("%d %d",&edge[i].first,&edge[i].second);
        int l = 0,r = m+1;
        while(l<r)
        {
            int mid = (l+r) >> 1,ch = 0;
            for(int i=1;i<=n;i++)   p[i] = i;
            for(int i=1;i<=mid;i++)
            {
                int ru = fin(edge[i].first),rv = fin(edge[i].second);
                if(ru!=rv)  p[ru] = rv;
            }
            for(int i=1;i<=w;i++)
            {
                int ru = fin(must[i].first),rv = fin(must[i].second);
                if(ru!=rv)  ch = 1;
            }
            if(ch)  l = mid+1;
            else    r = mid;
        }
        if(l>m)     printf("C#%d: -1\n",run);
        else        printf("C#%d: %d\n",run,l);
    }
    return 0;
}
