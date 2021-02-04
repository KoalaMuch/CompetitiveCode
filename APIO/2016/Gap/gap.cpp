#include "gap.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
vector< long long > v;
long long findGap(int T, int N)
{
    long long ans = 0;
    if(T==1)
    {
        long long l = -1,r = 4e18;
        for(int i=1;i<=(N+1)/2;i++)
        {
            long long mn,mx;
            MinMax(l+1,r-1,&mn,&mx);
            a[i] = l = mn;
            a[N-i+1] = r = mx;
        }
        for(int i=2;i<=N;i++)   ans = max(ans,a[i]-a[i-1]);
    }
    else
    {
        long long mn,mx,w1,w2,m;
        MinMax(0,4e18,&mn,&mx);
        if(N>2) w1 = (mx-mn-1)/(long long)(N-2)+1;
        if(N>2) w2 = (mx-mn-1)/(long long)(N-2);
        if(N>2) m = (mx-mn-1)%(N-2);
//        printf("%lld %lld %lld %lld %lld\n",w1,w2,m,mx,mn);
        v.push_back(mn),v.push_back(mx);
        long long last = mn;
        for(int i=1;i<=N-2;i++)
        {
           if(i<=m) MinMax(last+1,last+w1,&mn,&mx),last = last+w1;
           else     MinMax(last+1,last+w2,&mn,&mx),last = last+w2;
           if(mn!=-1)   v.push_back(mn),v.push_back(mx);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)   ans = max(ans,v[i+1]-v[i]);
    }
	return ans;
}
/*
2 3
0 1 100000000000000000
2 4
2 3 6 8
3 4 5 6 7
2 5
1 2 3 4 22
1 19 20 21 22

2 3 4 5 6 7 8     9 10 11 12 13 14 15   16 17 18 19 20 21

25/6
*/
