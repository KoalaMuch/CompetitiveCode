#include<bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
    int n = 0;
    scanf(" %s",s+1);
    for(int i=7,p=1;i>=1;i--,p*=16)
    {
        if(i!=1)    n+=(s[i]-'0')*p;
        else        n+=10*p;
    }
    printf("%d\n",(n%16)%2);
    return 0;
}
/*
A278832
170362930

A089956
168335702

A089957
168335703

A144045
169099333

n%7 -3
n%16 %2
*/
