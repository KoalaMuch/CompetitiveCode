#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
char a[N][N];
char b[N];
int c[N][N];
int main()
{
    int n,m,mn = 1e9;
    scanf("%d %d",&n,&m);
    memset(c,-1,sizeof c);
    for(int i=0;i<n;i++)
    {
        scanf(" %s",a[i]);
        for(int j=0;j<m;j++)
        {
            if(i-1>=0)  c[i][j] = c[i-1][j];
            if(a[i][j]=='X')    c[i][j] = i,mn = min(mn,n-i-1);
            if(a[i][j]=='#'&&c[i][j]!=-1)    mn = min(mn,i-c[i][j]-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')    b[j] = '#';
            else if(i>=mn&&a[i-mn][j]=='X')  b[j] = 'X';
            else                        b[j]='.';
        }
        printf("%s\n",b);
    }
    return 0;
}
/*
5 6
.XXXX.
...X..
......
#..###
######
*/
