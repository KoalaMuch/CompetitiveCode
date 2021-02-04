#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int f[N];
set< int > s;
int ans[N];
int a[N];
int cur = 1;

void upd(int i)
{
    while(i<N)  ++f[i],i+=i&-i;
}
int get(int i,int ret = 0)
{
    while(i)    ret+=f[i],i-=i&-i;
    return ret;
}
void add(int v)
{
    ans[cur] = v;
    s.erase(s.find(v));
    upd(v+1);
    cur++;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<2*n;i++)  s.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(s.count(a[i]))    add(a[i]);
        while(get(a[i])!=i-1)   add(*s.begin());
        while(cur-get(a[i]+1)!=i)    add(*(--s.end()));
    }
    for(int i=1;i<2*n;i++)  printf("%d ",ans[i]);
    return 0;
}
/*
13 10 3 8 8 10 10 11 11 10
13 1 10 3 2 8 20 4 19 5 18 6
*/
