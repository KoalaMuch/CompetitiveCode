#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char a[N];
char b[N];
vector< int > ans;
int p[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int del = 0,j;
        scanf(" %s",a+1);
        n = strlen(a+1);
        for(int i=1;i<=n;i++)   b[i] = a[n-i+1];
        for(int i=1;i<=n/2;i++)
        {
            if(a[i]!=b[i])  break;
            ans.push_back(i),ans.push_back(n-i+1);
            del = i;
        }
        int mx = 0,st,en;
        j = 0;
        for(int i=2;i<=n-del*2;i++)
        {
            while(j&&a[i+del]!=a[j+del+1])  j = p[j];
            if(a[i+del]==a[j+del+1])    ++j;
            p[i] = j;
        }
        j = 0;
        for(int i=1;i<=n-del*2;i++)
        {
            while(j&&b[i+del]!=a[j+del+1]) j = p[j];
            if(b[i+del]==a[j+del+1])    ++j;
        }
        if(j>mx)    mx = j,st = del+1,en = del+j;
        j = 0;
        for(int i=2;i<=n-del*2;i++)
        {
            while(j&&b[i+del]!=b[j+del+1])  j = p[j];
            if(b[i+del]==b[j+del+1])    ++j;
            p[i] = j;
        }
        j = 0;
        for(int i=1;i<=n-del*2;i++)
        {
            while(j&&a[i+del]!=b[j+del+1]) j = p[j];
            if(a[i+del]==b[j+del+1])    ++j;
        }
        if(j>mx)    mx = j,en = n-(del+1)+1,st = n-(del+j)+1;
        if(mx>0)  for(int i=st;i<=en;i++) ans.push_back(i);
        sort(ans.begin(),ans.end());
        for(auto &x:ans)    printf("%c",a[x]);
        printf("\n");
        ans.clear();
    }
    return 0;
}
