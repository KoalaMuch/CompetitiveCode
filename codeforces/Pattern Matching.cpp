#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char s[N][6];
map< string,int > mp;
vector< int > g[N];
int deg[N];
queue< int > q;
vector< int > seq;
char S[6];
char cre[6];
int main()
{
    int n,m,k,u,v;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",s[i]+1);
        mp[s[i]+1] = i;
    }
    bool ch = true;
    for(int i=1;i<=m;i++)
    {
        bool found = false;
        scanf(" %s %d",S+1,&u);
        for(int j=0;j<(1<<k);j++)
        {
            for(int l=1;l<=k;l++)
            {
                if((1<<(l-1))&j)    cre[l] = S[l];
                else                cre[l] = '_';
            }
            if(!strcmp(cre+1,s[u]+1)) found = true;
            else
            {
                v = mp[cre+1];
                if(v!=0)    g[u].push_back(v),++deg[v];
            }
        }
        if(found==false)    ch = false;
    }
    for(int i=1;i<=n;i++)   if(!deg[i]) q.push(i);
    while(!q.empty())
    {
        int now = q.front();q.pop();
        seq.push_back(now);
        for(auto &x:g[now])
        {
            --deg[x];
            if(!deg[x]) q.push(x);
        }
    }
    if(ch==false || seq.size()!=n)  printf("NO\n");
    else
    {
        printf("YES\n");
        for(auto &x:seq)    printf("%d ",x);
    }
    return 0;
}
