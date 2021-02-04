#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int fw[N];
char s[N];
stack< int > st[26];
void upd(int i)
{
    while(i<N)  ++fw[i],i+=i&-i;
}
int query(int i,int ret = 0)
{
    while(i)    ret+=fw[i],i-=i&-i;
    return ret;
}
int main()
{
    int n;
    long long ans = 0;
    scanf("%d %s",&n,s+1);
    for(int i=1;i<=n;i++)   st[s[i]-'a'].push(i);
    for(int i=1;i<=n;i++)
    {
        int cur = s[i]-'a';
        ans+=(n-i+1)-(st[cur].top()-query(st[cur].top()));
        upd(st[cur].top()+1);
        st[cur].pop();
    }
    printf("%lld\n",ans);
    return 0;
}
