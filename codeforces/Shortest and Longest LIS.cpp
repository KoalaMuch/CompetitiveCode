#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
int a[N];
int b[N];
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&n,s+1);
        int p1 = n,p2 = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='<') b[i]=p2++;
        }
        for(int i=1;i<n;i++)
        {
            int st = i;
            while(s[i]=='<')    ++i;
            for(int j=st;j<i;j++)   a[j+1]=p1-(i-j-1);
            p1-=i-st;
        }
        b[n]=p2++;
        p2 = n;
        for(int i=1;i<=n;i++)
        {
            if(!a[i])   a[i] = p1--;
            if(!b[i])   b[i] = p2--;
        }
        for(int i=1;i<=n;i++)   printf("%d ",a[i]),a[i] = 0;
        printf("\n");
        for(int i=1;i<=n;i++)   printf("%d ",b[i]),b[i] = 0;
        printf("\n");
    }
    return 0;
}
