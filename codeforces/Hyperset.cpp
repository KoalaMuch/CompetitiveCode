#include<bits/stdc++.h>
using namespace std;
const int N = 1505;
const int K = 35;
char str[N][K];
map< string,int > mp;
int main()
{
    int n,len,ans = 0;
    scanf("%d %d",&n,&len);
    for(int i=1;i<=n;i++)   scanf(" %s",str[i]),++mp[str[i]];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            string now;
            for(int k=0;k<len;k++)
            {
                if(str[i][k]==str[j][k])    now+=str[i][k];
                else if(str[i][k]!='S'&&str[j][k]!='S') now+='S';
                else if(str[i][k]!='E'&&str[j][k]!='E') now+='E';
                else if(str[i][k]!='T'&&str[j][k]!='T') now+='T';
            }
            ans+=mp[now];
        }
    }
    printf("%d\n",ans/3);
    return 0;
}
