#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct A
{
    string s;
    bool operator<(const A&o)const
    {
        return s<o.s;
    }
};
A a[N];
char ans[N*40];
int main()
{
    int n,len = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   cin >> a[i].s;
    sort(a+1,a+n+1);
    int cur = 0;
    for(int i=1;i<=n;i++)
    {
        int match = 0;
        for(int j=0;i!=1&&j<a[i].s.size();j++)
        {
            if(j>=a[i-1].s.size()||a[i].s[j]!=a[i-1].s[j])  break;
            match++;
        }
        while(cur>match)    ans[len++] = '-',--cur;
        while(cur<a[i].s.size())    ans[len++] = a[i].s[cur],++cur;
        ans[len++] = 'P';
    }
    printf("%d\n",len);
    for(int i=0;i<len;i++)    printf("%c\n",ans[i]);
    return 0;
}
