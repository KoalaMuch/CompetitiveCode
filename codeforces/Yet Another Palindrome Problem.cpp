#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int ch = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(int i=3;i<=n;i++)
        {
            for(int j=i-2;j>=1;j--)
            {
                ch|=a[i]==a[j];
            }
        }
        printf(ch ? "YES\n" : "NO\n");
    }
    return 0;
}
