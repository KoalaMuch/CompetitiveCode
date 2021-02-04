#include<bits/stdc++.h>
using namespace std;
int ch(int a,int b,int c,int d,int e,int f)
{
    return a>=c&&a<=e&&b>=d&&b<=f;
}
int main()
{
    int a,b,c,d,x,y,x1,y1,x2,y2,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);
        if((a||b)&&x1==x2)  printf("No\n");
        else if((c||d)&&y1==y2) printf("No\n");
        else printf(ch(x,y,x1,y1,x2,y2)&&ch(x+b-a,y+d-c,x1,y1,x2,y2) ? "Yes\n" : "No\n");
    }
    return 0;
}
