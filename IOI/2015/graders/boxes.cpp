#include "boxes.h"
#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
deque< pair< int,int > > deq;
long long ans;
long long delivery(int n, int k, int l, int p[]) {
    for(int i=0;i<n;i++)
    {
        if(i&&p[i]==p[i-1]) ++deq.back().second;
        else                deq.push_back(p[i],1);
    }
    int lst = 0;
    while(!deq.empty())
    {
        if
    }
    return 0;
}
