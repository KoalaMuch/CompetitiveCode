#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,a,b;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&a,&b);
        long long dif = abs(a-b);
        for(long long i=0;i<=1e9;i++)
        {
            if(i==45000)    printf("%lld\n",(i*(i+1))/2);
            if((i*(i+1))/2>dif)
            {
                printf("%lld\n",i);
                printf("%lld\n",i-1+(dif-((i-1)*i)/2)*2);
                break;
            }
        }
    }
    return 0;
}
