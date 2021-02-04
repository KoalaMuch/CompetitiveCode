#include<bits/stdc++.h>
using namespace std;
const int N = 104;
char s[N];
bool check(int l,int r)
{
    while(l<r)
    {
        if(s[l]!=s[r])  return false;
        ++l,--r;
    }
    return true;
}
int main()
{
    scanf(" %s",s+1);
    int n = strlen(s+1);
    printf(check(1,n)&&check(1,(n-1)/2)&&check((n+3)/2,n) ? "Yes\n" : "No\n");
}
