#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< int > factor[N];
int p[N];
int c[N];
bool mk[N];
bool mk2[N];
vector< int > vec;
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=1;i<=200000;i++)
    {
        if(factor[i].size()!=0) continue;
        for(int j=i;j<=200000;j+=i) factor[j].push_back(i);
    }
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&p[i]);
        for(int i=1;i<=n;i++)   scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
        {
            int now = p[i];
            if(mk[now])  continue;
            mk[now] = true;
            vec.push_back(now);
            while(p[now]!=now)    mk[p[now]] = true,vec.push_back(p[now]),now = p[now];
            int sz = vec.size();
            for(auto &x:factor[sz])
            {

            }
        }
    }
    return 0;
}
