#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
char str[N];
int main()
{
    freopen("alchemy_input.txt","r",stdin);
    freopen("alchemy_output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        int A = 0,B = 0;
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)
        {
            A+=str[i]=='A';
            B+=str[i]=='B';
        }
        char ans = abs(A-B)==1 ? 'Y' : 'N';
        printf("Case #%d: %c\n",x,ans);
    }
    return 0;
}
