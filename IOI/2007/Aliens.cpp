#include<bits/stdc++.h>
using namespace std;
pair< long long,long long > st;
pair< long long,long long > lft;
pair< long long,long long > rgt;
pair< long long,long long > up;
pair< long long,long long > lftup;
long long n;
long long cnt;
bool ask(pair< long long,long long > a)
{
    if(a.first<=0||a.second<=0||a.first>n||a.second>n)  return false;
    string ans;
    cout << "examine " << a.first << " " << a.second << endl;
    cin >> ans;
    return ans[0]=='t';
}
void ans(pair< long long,long long > a)
{
    cout<<"solution "<<a.first<<" "<<a.second<<endl;
}
int main()
{
    long long big;
    cin >> n >> st.first >> st.second;
    //get up
    up = st,big = -1;
    for(long long i=0;i<=32;i++)
    {
        if(up.second+(1ll<<i)>n||!ask({up.first,up.second+(1ll<<i)})) break;
        big = i;
    }
    if(big!=-1) up.second+=(1ll<<big);
    for(long long i=big-1;i>=0;i--)
    {
        if(up.second+(1ll<<i)>n||!ask({up.first,up.second+(1ll<<i)})) continue;
        up.second+=(1ll<<i);
    }
    //get right
    rgt = st,big = -1;
    for(long long i=0;i<=32;i++)
    {
        if(rgt.first+(1ll<<i)>n||!ask({rgt.first+(1ll<<i),rgt.second})) break;
        big = i;
    }
    if(big!=-1) rgt.first+=(1ll<<big);
    for(long long i=big-1;i>=0;i--)
    {
        if(rgt.first+(1ll<<i)>n||!ask({rgt.first+(1ll<<i),rgt.second})) continue;
        rgt.first+=(1ll<<i);
    }
    //get left
    lft = st,big = -1;
    for(long long i=0;i<=32;i++)
    {
        if(lft.first-(1ll<<i)<=0||!ask({lft.first-(1ll<<i),lft.second})) break;
        big = i;
    }
    if(big!=-1) lft.first-=(1ll<<big);
    for(long long i=big-1;i>=0;i--)
    {
        if(lft.first-(1ll<<i)<=0||!ask({lft.first-(1ll<<i),lft.second})) continue;
        lft.first-=(1ll<<i);
    }
    long long m = rgt.first-lft.first+1;
    lftup = {lft.first,up.second};
    while(true)
    {
        if(lftup.first-2*m<=0||!ask({lftup.first-2*m,lftup.second}))    break;
        lftup.first-=2*m;
    }
    while(true)
    {
        if(lftup.second+2*m>n||!ask({lftup.first,lftup.second+2*m}))    break;
        lftup.second+=2*m;
    }
    if(!ask({lftup.first-1,lftup.second+1}))    ans({lftup.first+2*m+m/2,lftup.second-2*m-m/2});
    else                                        ans({lftup.first+m+m/2,lftup.second-m-m/2});
    return 0;
}
/*
19 7 4
examine 7 5
0
examine 8 4
0
examine 6 4
1
examine 5 4
1
examine 3 4
0
examine 4 4
0
examine 5 10
1
examine 5 16
1

15 15 15
examine 14 15
t
examine 13 15
t
examine 11 15
t
examine 7 15
f
examine 9 15
f
examine 10 15
f
examine 1 15
t
solution 13 3

15 8 8
examine 8 9
true
examine 8 10
false
examine 9 8
true
examine 10 8
false
examine 7 8
true
examine 6 8
true
examine 4 8
false
examine 5 8
false


*/
