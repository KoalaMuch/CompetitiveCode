#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
bool l[N];
bool r[N];
char str[N];
int main()
{
    scanf(" %s",str+1);
    int n = strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='2')                      l[i] = r[i] = true;
        if(str[i]=='1'&&str[i-1]=='2')       l[i] = true;
        else if(str[i]=='1'&&str[i+1]=='2')  r[i] = true;
        else if(str[i]=='1'&&str[i-1]=='0')  r[i] = true;
        else if(str[i]=='1'&&str[i+1]=='0')  l[i] = true;
        else if(str[i]=='1')
        {
            int cnt = 1,st = i;
            while(str[i+1]=='1'&&str[i+2]!='2')  ++i,++cnt;
            if(cnt%2&&str[st-1]=='?')   r[st-1] =  l[st] = true,++st;
            else if(cnt%2) r[i] = l[i+1]  = true;
            for(int j=st;j<=i;j+=2) r[j] =  l[j+1] = true;
        }
        if(r[i-1])  l[i] = true;
    }
    for(int i=1;i<=n;i++)
    {
        if(i-1)
        {
            if(l[i]||r[i-1])    printf("-");
            else                printf(".");
        }
        printf("x");
    }
    return 0;
}