#include<bits/stdc++.h>
using namespace std;
const int N = 130;
string ret;
int col[2*N];
int cnt[2];
string investigate_colors(int n)
{
    int state = 0;
    ++cnt[0];
    int x = use_device(0,1);
    for(int i=1;i<2*n-1;i+=2)
    {
        int y = use_device(i,i+1);
        state = cnt[0]<cnt[1];
        int pos;
        for(int j=0;j<i;j++)    if(col[j]==state)   {pos=j;break;}
        if(y==x-2)
        {
            if(!state)  col[i] = 1;
            else        col[i] = 0;
        }
        else if(y==x+2)
        {
            if(!state)  col[i] = 0;
            else        col[i] = 1;
        }
        else
        {
            int z = use_device(pos,i+1);
            if(z==x)    col[i] = col[i+1] = col[pos];
            else        col[i] = col[i+1] = col[pos]^1;
        }
        ++cnt[col[i]],++cnt[col[i+1]];
    }
    if(cnt[0]>cnt[1])   col[2*n-1] = 1;
    for(int i=0;i<2*n;i++)  ret+=col[i] ? 'B' : 'R';
    return ret;
}
