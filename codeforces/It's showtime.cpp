#include<bits/stdc++.h>
using namespace std;
int f[1000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int a=1;a<=999;a++)
    {
        for(int b=1;b<=999;b++)
        {
            if(a*1000+b==n)
            {
                for(int i=0;i<3;i++)        f[i] = max(1,i)%b;
                for(int i=3;i<=1000;i++)    f[i] = i*f[i-2]%b;
                printf("%d\n",f[a]);
                return 0;
            }
        }
    }

    return 0;
}
