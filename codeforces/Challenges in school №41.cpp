#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
char s[N];
int main()
{
    int n,k,mn = 0,mx = 0;
    scanf("%d %d %s",&n,&k,s+1);
    for(int i=1,R=0;i<=n;i++)
    {
        if(s[i]=='L')   mn+=R;
        else            ++R;
    }
    printf("%d\n",mn);
    return 0;
}
