#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ch = 0;
        for(int i=1;i<=n;i+=2)  ch|=a[i]!=a[i+1];
        printf(n%2==1||ch ? "T\n" : "HL\n");
    }
    return 0;
}
