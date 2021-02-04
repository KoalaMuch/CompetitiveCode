#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[4];
char str[N];
int lft[4];
char ans[N];
int main()
{
    int n,q;
    scanf("%d",&q);
    while(q--)
    {
        for(int i=0;i<4;i++)    scanf("%d",&a[i]);
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)   ++lft[str[i]-'0'-1];
        for(int i=1;i<=n;i++) 
        {
            int nxt = 0,now = str[i]-'0'-1;
            bool ch = false;
            for(int j=0;j<4;j++)
            {
                if(a[j]&&j!=now&&!nxt) nxt = j+1;   
                if(n-i-lft[j]-a[j]+(j==now)<0){
                --a[j],--lft[now],ch = true;
                ans[i] = (j+1)+'0';
                break;
                }
            }
            if(!ch)
            {
                --a[nxt-1],--lft[now];
                ans[i] = nxt+'0';
            }
        }
        ans[n+1] = '\0'; 
        printf("%s\n",ans+1);
    }
    return 0;
}
