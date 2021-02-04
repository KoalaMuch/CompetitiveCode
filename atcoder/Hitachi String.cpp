#include<bits/stdc++.h>
using namespace std;
char str[15];
int main()
{
    int n;
    bool ch = false;
    scanf(" %s",str+1);
    n = strlen(str+1);
    for(int i=1;i<=n;i+=2)
    {
        ch|=str[i]!='h'||str[i+1]!='i';
    }
    printf(ch ? "No\n" : "Yes\n");
    return 0;
}
