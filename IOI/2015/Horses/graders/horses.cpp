#include "horses.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long sm[2000005]; //return index of best value
pair< long long,long long > sm2[2000005]; //quick multiply
long long x[500005];
long long y[500005];
long long n;
void up2(long long l,long long r,long long idx,long long now)
{
    if(l>idx||r<idx)    return;
    if(l==r)    {sm2[now].first = x[l];return;}
    long long mid = (l+r) >> 1;
    up2(l,mid,idx,now<<1),up2(mid+1,r,idx,now<<1|1);
    long long v = sm2[now<<1].first*sm2[now<<1|1].first;
    sm2[now] = {v%mod,sm2[now<<1].second||sm2[now<<1|1].second||v>=mod};
}
pair< long long,long long > GetQMul(long long l,long long r,long long ll,long long rr,long long now)
{
    if(l>rr||r<ll)  return {1ll,0ll};
    if(l>=ll&&r<=rr)    return sm2[now];
    long long mid = (l+r) >> 1;
    pair< long long,long long > a = GetQMul(l,mid,ll,rr,now<<1),b = GetQMul(mid+1,r,ll,rr,now<<1|1);
    long long v = a.first*b.first;
    return {v%mod,a.second||b.second||v>=mod};
}
long long comp(long long i,long long j)
{
    long long want = (y[i]+y[j]-1)/y[j];
    pair< long long,long long > a = GetQMul(1,n,i+1,j,1);
    if(a.second==1||a.first>=want)  return j;
    return i;
}
void up1(long long l,long long r,long long idx,long long now)
{
    if(l>idx||r<idx)    return ;
    if(l==r)    {sm[now] = l;return;}
    long long mid = (l+r) >> 1;
    up1(l,mid,idx,now<<1),up1(mid+1,r,idx,now<<1|1);
    if(sm[now<<1]&&sm[now<<1|1])sm[now] = comp(sm[now<<1],sm[now<<1|1]);
}
int init(int N, int X[], int Y[]) {
    n = N;
    for(long long i=0;i<N;i++)    x[i+1] = X[i],y[i+1] = Y[i];
    for(long long i=1;i<=n;i++)   up2(1,n,i,1);
    for(long long i=1;i<=n;i++)   up1(1,n,i,1);
	return GetQMul(1,n,1,sm[1],1).first*y[sm[1]]%mod;
}
int updateX(int pos, int val) {
    x[pos+1] = val;
    up2(1,n,pos+1,1);
    up1(1,n,pos+1,1);
	return GetQMul(1,n,1,sm[1],1).first*y[sm[1]]%mod;
}
int updateY(int pos, int val) {
    y[pos+1] = val;
    up1(1,n,pos+1,1);
	return GetQMul(1,n,1,sm[1],1).first*y[sm[1]]%mod;
}
