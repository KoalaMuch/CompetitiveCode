#include<bits/stdc++.h>
using namespace std;
char cre[8];
char cre2[8];
int main()
{
    for(int i=1;i<=5;i++)   cre[i] = cre2[i] = 'a';
    cre2[5] = 'b';
    printf("%s %s %d\n",cre+1,cre2+1,strcmp(cre+1,cre2+1));
}
