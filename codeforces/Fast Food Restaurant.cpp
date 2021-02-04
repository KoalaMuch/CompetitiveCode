#include<bits/stdc++.h>
using namespace std;
int A[5];
int main()
{
    int q,a,b,c;
    scanf("%d",&q);
    while(q--)
    {
        int ans = 0;
        scanf("%d %d %d",&A[0],&A[1],&A[2]);
        sort(A,A+3);
        a = A[0],b = A[1],c = A[2];
//        printf("%d %d %d\n",a,b,c);
        if(a)   --a,++ans;
        if(b)   --b,++ans;
        if(c)   --c,++ans;
        if(b&&c)    --b,--c,++ans;
        if(a&&c)    --a,--c,++ans;
        if(a&&b)    --a,--b,++ans;
        if(a&&b&&c) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
