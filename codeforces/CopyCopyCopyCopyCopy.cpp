#include<bits/stdc++.h>
using namespace std;
vector< int >  v;
int main()
{
    int T,n,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)   scanf("%d",&x),v.push_back(x);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        printf("%d\n",v.size());
        v.clear();
    }
    return 0;
}
