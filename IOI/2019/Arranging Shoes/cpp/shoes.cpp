#include "shoes.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
const int N = 2e5+5;
using namespace std;
long long f[N];
void up(int i,int v)
{
    while(i<N)  f[i]+=v,i+=i&-i;
}
int query(int i,int ret  = 0)
{
    while(i)    ret+=f[i],i-=i&-i;
    return ret;
}
queue< int > pos[N];
queue< int > neg[N];
long long count_swaps(std::vector<int> s) {
    int n = s.size();
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]<0)
        {
            if(pos[-s[i]].empty())  neg[-s[i]].push(i+1);
            else
            {
                int cur = pos[-s[i]].front();   pos[-s[i]].pop();
                int realpos = cur+query(cur);
                ans+=i-realpos+1;
                up(cur,1),up(i+1,-1);
            }
        }
        else
        {
            if(neg[s[i]].empty())   pos[s[i]].push(i+1);
            else
            {
                int cur = neg[s[i]].front(); neg[s[i]].pop();
                int realpos = cur+query(cur);
                ans+=i-realpos;
                up(cur+1,1),up(i+1,-1);
            }
        }
    }
	return ans;
}
