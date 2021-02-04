#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
char s[N];
vector< char > ans1;
vector< char > ans2;
void pr(vector< char > v)
{
    for(char x : v) printf("%c",x);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d %s",&n,s+1);
    if(!(n&1)) return puts("NOT POSSIBLE"),0;
    int cur = 1,cnt = 0;
    bool first = false;
    for(int i=n/2+1;i<=n;i++)
    {
        if(cur<n/2+1&&s[i]==s[cur])    ++cur;
    }
    if(cur==n/2+1)
    {
        ++cnt,first = true;
        for(int i=1;i<=n/2;i++) ans1.push_back(s[i]);
    }
    cur = (n+1)/2+1;
    for(int i=1;i<=(n+1)/2;i++)
    {
        if(cur<n+1&&s[i]==s[cur]) ++cur;
    }
    if(cur==n+1)
    {
        for(int i=(n+1)/2+1;i<=n;i++) ans2.push_back(s[i]);
        ++cnt;
    }
    if(cnt==0)
    {
        printf("NOT POSSIBLE\n");
    }
    if(cnt==1)
    {
        if(first)   pr(ans1);
        else        pr(ans2);
    }
    if(cnt==2)
    {
        if(ans1==ans2)  pr(ans1);
        else            printf("NOT UNIQUE\n");
    }
    return 0;
}
/*
7
ABXCABC

6
ABCDEF

17
AABBAABBAABBAABBA
*/
