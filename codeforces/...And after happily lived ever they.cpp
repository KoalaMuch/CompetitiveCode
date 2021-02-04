#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,X = 0;
    scanf("%d",&n);
    for(int i=0;i<=63;i++)  X^=i;
    printf("%d\n",X^n);
    return 0;
}
