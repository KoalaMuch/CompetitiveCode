#include <bits/stdc++.h>
using namespace std;
const int N = 45;
int a[N];
int tmp[N];
int l[3],r[3];
int main()
{
    int n,L,R;
    for(int i=0;i<3;i++)    l[i] = r[i] = 1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++)   scanf("%d",&a[i]);
    L = n/2,R = n-L;
    if(n<=20)   L = 0,R = n;
    int limL = (1<<L)-1,limR = (1<<R)-1;
    for(int i=0;i<limL;i++)
    {
        if(i&(1<<(L-1)))    continue;
        int cnt = 0;
        for(int j=0;j<L;j++)    tmp[j] = a[j];
        for(int j=0;j<L;j++)
        {
            if((1<<j)&i)
            {
                if(j-1>=0)  tmp[j-1]^=1;
                tmp[j]^=1;
                tmp[j+1]^=1;
            }
        }
        for(int j=0;j<L;j++)    cnt = cnt+tmp[j];
        if(cnt<=2)
        {
            int ch = 0;
            for(int j=L-1;j>=L-cnt;j--) ch|=(!tmp[j]);   
            if(!ch) l[cnt] = min(l[cnt],__builtin_popcount(i)); 
        }
    }
    for(int i=0;i<limR;i++)
    {
        if(i&1) continue;
        int cnt = 0;
        for(int j=0;j<R;j++)    tmp[j] = a[j+L];
        for(int j=0;j<R;j++)    if((1<<j)&i)    tmp[j-1]^=1,tmp[j]^=1,tmp[j+1]^=1;
        for(int j=0;j<R;j++)    cnt = cnt+tmp[j];
        if(cnt<=2)
        {            
            int ch = 0;
            for(int j=0;j<cnt;j++) ch|=(!tmp[j]);   
            if(!ch) r[cnt] = min(r[cnt],__builtin_popcount(i)); 
        }
    }
    if(!L)  memset(l,0,sizeof l);
    int ans = min(l[0]+r[0],min(l[1]+r[2],l[2]+r[1])+1);
    if(n>20)    printf( (ans>n) ? "-1\n" : "%d\n",ans);
    else        printf( min(r[0],r[2]+1)>n ? "-1\n" : "%d\n",min(r[0],r[2]+1));
    return 0;
}
