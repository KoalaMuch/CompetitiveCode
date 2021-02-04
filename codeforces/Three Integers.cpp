#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        int mn = 1e9,A,B,C;
        scanf("%d %d %d",&a,&b,&c);
        for(int i=1;i<=10000;i++)
        {
            for(int j=i;j<=20000;j+=i)
            {
                for(int k=j;k<=20000;k+=j)
                {
                    int v = abs(a-i)+abs(b-j)+abs(c-k);
                    if(v<mn)   mn = v,A=i,B=j,C=k;
                }
            }
        }
        printf("%d\n%d %d %d\n",mn,A,B,C);
    }
    return 0;
}
