#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    long long n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld",&n);
        while(1)
        {
            long long tmp = n;
            bool ch = true;
            while(tmp>0)
            {
                long long cur = tmp%10;
                if(cur>0 && n%cur)   ch = false;
                tmp/=10;
            }
            if(ch)  {printf("%lld\n",n);break;}
            n+=1;
        }
    }
    return 0;
}
