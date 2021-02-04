#include<bits/stdc++.h>
using namespace std;
char s[4];
int main()
{
    scanf(" %s",s);
    printf(s[0]==s[1]&&s[1]==s[2] ? "Won\n" : "Lost\n");
    return 0;
}
