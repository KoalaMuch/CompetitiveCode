#include "molecules.h"
#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector< int > ans;
long long dpl[N];
long long dpr[N];
pair< int,int > a[N];
std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    int n = w.size();
    for(int i=1;i<=n;i++)   a[i] = {w[i-1],i-1};
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)   dpl[i] = a[i].first+dpl[i-1];
    for(int i=n;i>=1;i--)   dpr[i] = a[i].first+dpr[i+1];
    for(int i=0;i<=n;i++)
    {
        int p = i+1,q = n+1;
        while(p<q)
        {
            int mid = (p+q) >> 1;
            if(dpl[i]+dpr[mid]>u)   p=mid+1;
            else                    q=mid;
        }
        if(dpl[i]+dpr[p]>=l&&dpl[i]+dpr[p]<=u&&i<p)
        {
            for(int j=1;j<=i;j++)   ans.push_back(a[j].second);
            for(int j=p;j<=n;j++)   ans.push_back(a[j].second);
            return ans;
        }

    }
    return ans;
}
/*
4 10 20 15 16 17 18
4 15 17 6 8 8 7
4 14 15 5 5 6 6
*/
