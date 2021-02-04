#include<bits/stdc++.h>
using namespace std;
const int N = 505;
char a[N][N];
char b[N][N];
char c[N][N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s",a[i]+1);
        for(int j=1;j<=m;j++)   b[i][j]=a[i][j],c[i][j]=a[i][j];
        if(i==1||i==n)  continue;
        b[i][1]='#',c[i][m]='#';
        if(i%2) for(int j=2;j<=m-1;j++) b[i][j]='#';
        else    for(int j=2;j<=m-1;j++) c[i][j]='#';
    }
    for(int i=1;i<=n;i++)   printf("%s\n",b[i]+1);
    printf("\n");
    for(int i=1;i<=n;i++)   printf("%s\n",c[i]+1);
    return 0;
}
/*
5 5
.....
..#..
.#.#.
..#..
.....
*/
