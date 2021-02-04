#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char str[N];
int main()
{
    int q,n,lst;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %s",&n,str+1);
        lst = 3;
        for(int i=1;i<=n;i++)
        {
            if(str[i]-'0'+1==lst)   printf("0"),lst = str[i]-'0';
            else                    printf("1"),lst = str[i]-'0'+1;
        }
        printf("\n");
    }
    return 0;
}
