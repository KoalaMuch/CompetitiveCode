#include<bits/stdc++.h>
using namespace std;
int bit[50];//-1 = south
char ans[50];
char pr(int now)
{
    if(now==-1)  return 'W';
    if(now==1)  return 'E';
    if(now==-2)  return 'S';
    if(now==2)  return 'N';
}
void solve()
{
    int x,y,len = 0,chx = 1,chy = 1;
    scanf("%d %d",&x,&y);
    if(x<0) chx = -1,x*=-1;
    if(y<0) chy = -1,y*=-1;
    for(int i=30;i>=0;i--)
    {
        int xx = (1<<i)&x,yy = (1<<i)&y;
        if(xx&&yy)
        {
            int ch = 0,j;
            for(j=i-1;j>=0;j--)
            {
                int X = (1<<j)&x,Y = (1<<j)&y;
                if(X!=0&&Y==0)  {ch = 1;break;}
                if(X==0&&Y!=0)  {ch = 2;break;}
            }
            if(!ch) {printf("IMPOSSIBLE\n");return ;}
//            printf("[%d %d %d]\n",i,j,ch);
            int k,ch2 = 0;
            for(int k=i+1;k<=30;k++)    if(!bit[i])
            bit[i+1] = ch;bit[j] = -ch;
            len = max(len,i+1);
            for(int k=i;k>=j+1;k--)
            {
                int X = (1<<k)&x,Y = (1<<k)&y;
                if(X!=0&&Y!=0) bit[k] = 3-ch;
                else           bit[k] = -ch;
//                printf("[[%d %d %d %d]]\n",k,bit[k],X,Y);
            }
            i=j;
        }
        else if(xx==0&&yy!=0)   bit[i] = 2,len = max(len,i);
        else if(xx!=0&&yy==0)   bit[i] = 1,len = max(len,i);
//        else if(len!=0)         {printf("IMPOSSIBLE\n");return;}
    }
    for(int i=0;i<=len;i++) if(!bit[i]) {printf("IMPOSSIBLE\n");return;}
    ans[len+1] = '\0';
    for(int i=0;i<=len;i++)
    {
        if(abs(bit[i])==1)  ans[i] = pr(bit[i]*chx);
        else                ans[i] = pr(bit[i]*chy);
    }
    printf("%s\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}

