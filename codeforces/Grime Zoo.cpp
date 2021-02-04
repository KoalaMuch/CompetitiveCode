#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char s[N];
long long fw[N][2];
void upd(long long i,long long col)
{
    while(i<N)  fw[i][col]++,i+=i&-i;
}
long long get(long long i,long long col,long long tot = 0)
{
    while(i)    tot+=fw[i][col],i-=i&-i;
    return tot;
}
int main()
{
    long long ans = 0,zero,one;
    long long n,x,y;
    scanf(" %s %lld %lld",s+1,&x,&y);
    n = strlen(s+1);
    for(long long i=1;i<=n;i++)   if(s[i]!='?')   upd(i,s[i]-'0');
    for(long long i=1;i<=n;i++)
    {
        if(s[i]=='0')   ans+=y*get(i,1);
        else if(s[i]=='1')  ans+=x*get(i,0);
        else
        {
            zero = y*get(i,1)+x*(get(n,1)-get(i,1));
            one  = x*get(i,0)+y*(get(n,0)-get(i,0));
            if(zero<one||(zero==one && x<y))    ans+=y*get(i,1),upd(i,0);
            else                                ans+=x*get(i,0),upd(i,1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
