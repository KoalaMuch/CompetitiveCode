#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        long long X = 0,S = 0,a;
        for(int i=1;i<=n;i++)   scanf("%lld",&a),X^=a,S+=a;
        printf("2\n%lld %lld\n",X,X+S);
    }
    return 0;
}
