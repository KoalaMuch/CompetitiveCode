#include<bits/stdc++.h>
using namespace std;
vector< int > odd;
vector< int > even;
int main()
{
    int q,n,x;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x%2) odd.push_back(i);
            else    even.push_back(i);
        }
        if(!even.empty())   printf("1\n%d\n",even[0]);
        else if(odd.size()>=2)  printf("2\n%d %d\n",odd[0],odd[1]);
        else                printf("-1\n");
        odd.clear(); even.clear();
    }
    return 0;
}
