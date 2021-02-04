#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int b[N];
int main()
{
    int n,m,k,A,B,x,mna = 1e9,mnb = 1e9,mn = 1e9;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]),mna = min(mna,a[i]);
    for(int i=1;i<=m;i++)   scanf("%d",&b[i]),mnb = min(mnb,b[i]);
    for(int i=1;i<=k;i++)   scanf("%d %d %d",&A,&B,&x),mn = min(mn,a[A]+b[B]-x);
    printf("%d\n",min(mna+mnb,mn));
}
