#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
char s[N];
int main()
{
    int n,q,k;
    scanf("%d",&q);
    while(q--)
    {
        int sc = 0,cnt = 0,cur = 0,save = 0,ch = 0;
        scanf("%d %d %s",&n,&k,s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='W')
            {
                ch = 1;
                sc+=1+(s[i-1]=='W');
                if(cnt!=0)
                {
                    if(i-cnt==1)  save = cnt;
                    else            a[++cur] = cnt;
                    cnt = 0;
                }
            }
            else            cnt++;
        }
        if(cnt!=0)  save+=cnt;
        sort(a+1,a+cur+1);
        for(int i=1;i<=cur;i++)
        {
            if(k>=a[i])
            {
                sc+=2*a[i]+1;
                k-=a[i];
            }
            else
            {
                sc+=2*k;
                k = 0;
            }
        }
        if(ch==0)
            printf("%d\n",max(0,2*k-1));
        else
            printf("%d\n",min(sc+2*min(k,save),2*n-1));
    }
    return 0;
}
