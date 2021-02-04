#include "cave.h"
//#include "grader.c"
#include<stdio.h>
void exploreCave(int n) {
    int s[n],d[n],ask[n];
    for(int i=0;i<n;i++)    s[i] = d[i] = -1;
    for(int i=0;i<n;i++)
    {
        int cor = 0;
        for(int j=0;j<n;j++)
        {
            if(s[j]==-1)    ask[j] = 0;
            else            ask[j] = s[j];
        }
        cor^=(tryCombination(ask)==i);
        int l = 0,r = n-1;
        while(l<r)
        {
            int mid = (l+r) >> 1;
            for(int j=l;j<=mid;j++)
            {
                if(s[j]==-1)    ask[j] = cor;
                else            ask[j] = s[j];
            }
            for(int j=mid+1;j<=r;j++)
            {
                if(s[j]==-1)    ask[j] = cor^1;
                else            ask[j] = s[j];
            }
            if(tryCombination(ask)==i)  l=mid+1;
            else                        r=mid;
        }
        d[l] = i;
        s[l] = cor;
    }
    answer(s,d);
}
