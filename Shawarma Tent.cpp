#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    int n,X,Y,x,y,mx = 0;
    scanf("%d %d %d",&n,&X,&Y);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        if(x<=X-1)  a[0]++;
        if(y>=Y+1)  a[1]++;
        if(x>=X+1)  a[2]++;
        if(y<=Y-1)  a[3]++;
        mx = max(mx,max( max(a[0],a[1]),max(a[2],a[3]) ) ); 
    }
    printf("%d\n",mx);
    if(mx==a[0])        printf("%d %d\n",X-1,Y);
    else if(mx==a[1])   printf("%d %d\n",X,Y+1);
    else if(mx==a[2])   printf("%d %d\n",X+1,Y);
    else                printf("%d %d\n",X,Y-1);
    return 0;
}