#include "ricehub.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long qs[N];
int besthub(int R, int L, int X[], long long B)
{
    int lo = 1,hi = R;
    for(long long i=R;i>=1;i--) X[i] = X[i-1];
    for(int i=1;i<=R;i++)   qs[i] = qs[i-1]+X[i];
    while(lo<hi)
    {
        int mid = (lo+hi+1) >> 1;
        long long mn = 1e18;
        for(int i=1;i<=R-mid+1;i++)
        {
            int st = i,en = i+mid-1;
            int div = (st+en) >> 1;
            long long suml = qs[div]-qs[st-1],sumr = qs[en]-qs[div],lenl = div-st+1,lenr = en-div;
            mn = min(mn,lenl*X[div]-suml+sumr-lenr*X[div]);
        }
        if(mn<=B)   lo=mid;
        else        hi=mid-1;
    }
    return lo;
}
