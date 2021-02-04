#include<bits/stdc++.h>
using namespace std;
const int N = 705;
int sz[N*N];
int p[N*N];
int h[N*N];
int v[N*N];
stack< pair< int,int > > st;
vector< pair< double,pair< int,int > > > vec;
int fin(int i)  {return p[i]==i ? i : fin(p[i]);}
int ans=1;
void Merge(int a,int b)
{
    if(h[a]==h[b]&&v[a]==v[b])
    {
        int aa = fin(a),bb = fin(b);
        if(aa!=bb)
        {
            ans = max(ans,sz[aa]+sz[bb]);
            if(sz[aa]>sz[bb])   p[bb] = aa,sz[aa]+=sz[bb];
            else                p[aa] = bb,sz[bb]+=sz[aa];
        }
        return ;
    }
    if(v[a]==v[b]) return ;
    double w = ((h[a]-h[b])*1.0)/(1.0*(v[b]-v[a]));
    if(w>=0)    vec.push_back({w,{a,b}});
}
void split()
{
    while(!st.empty())
    {
        int u = st.top().first,v = st.top().second;
        sz[u]-=sz[v],p[v] = v;
        st.pop();
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++) p[i] = i,sz[i] = 1;
    for(int i=1;i<=n*n;i++) scanf("%d",&h[i]);
    for(int i=1;i<=n*n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i-1) Merge((i-2)*n+j,(i-1)*n+j);
            if(j-1) Merge((i-1)*n+j-1,(i-1)*n+j);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        if(i&&vec[i].first!=vec[i-1].first) split();
        int a = fin(vec[i].second.first),b = fin(vec[i].second.second);
        if(a==b)    continue;
        ans = max(ans,sz[a]+sz[b]);
        if(sz[a]<sz[b]) p[a] = b,sz[b]+=sz[a],st.push({b,a});
        else            p[b] = a,sz[a]+=sz[b],st.push({a,b});
    }
    printf("%d\n",ans);
    return 0;
}
