#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5e4+5;
char str[N];
char cmp[N];
int cnt[N];
bool mk[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",str+1);
        int n = strlen(str+1);
        str[n+1] = '\0';
        int st = 0,ans = 0;
        for(int i=1;i<=n;i++)
        {
            cmp[++st] = str[i];
            cnt[st] = 1;
            while(str[i]==str[i+1]) ++cnt[st],++i;
        }
        cmp[st+1] = '\0';
        for(int i=1;i<=st;i++)
        {
            if(cmp[i]=='t'&&cmp[i+1]=='w'&&cmp[i+2]=='o'&&cnt[i+1]==1)
            {
                if(cmp[i+3]=='n'&&cmp[i+4]=='e'&&cnt[i+3]==1)
                {
                    int l = cnt[i]<cnt[i+1] ? 0 : 1,r = cnt[i+3]<cnt[i+4] ? 3 : 4;
                    if(cnt[i+l]+cnt[i+r]<cnt[i+2])    mk[i+l] = mk[i+r] = true;
                    else                mk[i+2] = true; 
                    ans+=min(cnt[i+l]+cnt[i+r],cnt[i+2]);
                    i+=4;
                }
                else
                {
                    if(cnt[i]<=min(cnt[i+1],cnt[i+2]))   mk[i] = true;
                    else if(cnt[i+1]<=min(cnt[i],cnt[i+2]))  mk[i+1] = true;
                    else    mk[i+2] = true;   
                    ans+=min(cnt[i],min(cnt[i+1],cnt[i+2]));
                    i+=2;
                }
            }
            if(cmp[i]=='o'&&cmp[i+1]=='n'&&cmp[i+2]=='e'&&cnt[i+1]==1)
            {
                if(cnt[i]<=min(cnt[i+1],cnt[i+2]))   mk[i] = true;
                else if(cnt[i+1]<=min(cnt[i],cnt[i+2]))  mk[i+1] = true;
                else    mk[i+2] = true;   
                ans+=min(cnt[i],min(cnt[i+1],cnt[i+2]));
                i+=2;
            }
        }
        int sum = 0;
        printf("%d\n",ans);
        for(int i=1;i<=st;i++)
        {
            if(mk[i])
            {
                for(int j=sum+1;j<=sum+cnt[i];j++)  printf("%d ",j);
            }
            sum+=cnt[i];
            cnt[i] = 0;
            mk[i] = false;
        }  
        printf("\n");
    }
    return 0;
}