#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
char s[N];
int mem[105][105];
int solve(int l,int r)
{
    if(mem[l][r]!=-1)   return mem[l][r];
    if(r-l==1)  return mem[l][r] = abs(s[r]-s[l]);
    int mid = (r-l+1) >> 1;
    return mem[l][r] = abs(solve(l,r-1)-solve(l+1,r));
}
int main()
{

    int n,q;
    scanf("%d",&q);
    while(q--)
    {
        memset(mem,-1,sizeof mem);
        scanf("%d %s",&n,s+1);
        printf("%d\n",solve(1,n));
    }
    return 0;
}
/*
1
200
12312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312123121231212312
*/
