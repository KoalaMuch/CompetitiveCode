#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
pair< long long,long long > opr[N];
vector< long long > all,t1,t2;
long long f[6][N];
//0 = count of type1
//1 = sum of type1
void upd(long long idx,long long i,long long v)
{
    while(i<N)    f[idx][i]+=v,i+=i&-i;
}
long long query(long long idx,long long i,long long ret = 0)
{
    while(i)  ret+=f[idx][i],i-=i&-i;
    return ret;
}
long long getsum(long long idx,long long l,long long r)
{
    if(l>r) return 0;
    long long low = 0,high = N;
    while(low<high)
    {
        long long mid = (low+high) >> 1;
        if(query(idx-1,mid)<r)  low = mid+1;
        else                    high = mid;
    }
    long long a = query(idx,low);
    low = 0,high = N;
    while(low<high)
    {
        long long mid = (low+high) >> 1;
        if(query(idx-1,mid)<(l-1))  low = mid+1;
        else                        high = mid;
    }
    long long b = query(idx,low);
    return a-b;
}
int main()
{
    long long n,cnt1 = 0,cnt2 = 0,idx;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %lld",&opr[i].first,&opr[i].second);
        all.push_back(abs(opr[i].second));
        if(opr[i].first==0) t1.push_back(abs(opr[i].second));
        else                t2.push_back(abs(opr[i].second));
    }
    sort(all.begin(),all.end()),all.resize(unique(all.begin(),all.end())-all.begin());
    sort(t1.begin(),t1.end()),t1.resize(unique(t1.begin(),t1.end())-t1.begin());
    sort(t2.begin(),t2.end()),t2.resize(unique(t2.begin(),t2.end())-t2.begin());
    for(long long i=1;i<=n;i++)
    {
        if(opr[i].first==0)
        {
            if(opr[i].second<0)
            {
                idx = lower_bound(t1.begin(),t1.end(),-opr[i].second)-t1.begin()+1;
                upd(0,idx,-1);
                upd(1,idx,opr[i].second);
                idx = lower_bound(all.begin(),all.end(),-opr[i].second)-all.begin()+1;
                upd(4,idx,-1);
                upd(5,idx,opr[i].second);
                --cnt1;
            }
            else
            {
                idx = lower_bound(t1.begin(),t1.end(),opr[i].second)-t1.begin()+1;
                upd(0,idx,1);
                upd(1,idx,opr[i].second);
                idx = lower_bound(all.begin(),all.end(),opr[i].second)-all.begin()+1;
                upd(4,idx,1);
                upd(5,idx,opr[i].second);
                ++cnt1;
            }
        }
        else
        {
            if(opr[i].second<0)
            {
                idx = lower_bound(t2.begin(),t2.end(),-opr[i].second)-t2.begin()+1;
                upd(2,idx,-1);
                upd(3,idx,opr[i].second);
                idx = lower_bound(all.begin(),all.end(),-opr[i].second)-all.begin()+1;
                upd(4,idx,-1);
                upd(5,idx,opr[i].second);
                --cnt2;
            }
            else
            {
                idx = lower_bound(t2.begin(),t2.end(),opr[i].second)-t2.begin()+1;
                upd(2,idx,1);
                upd(3,idx,opr[i].second);
                idx = lower_bound(all.begin(),all.end(),opr[i].second)-all.begin()+1;
                upd(4,idx,1);
                upd(5,idx,opr[i].second);
                ++cnt2;
            }
        }
        long long ans = getsum(5,cnt1+1,cnt1+cnt2);
        if(getsum(5,cnt1+1,cnt1+cnt2)==getsum(3,1,cnt2)&&cnt2>0)    ans-=getsum(3,1,1),ans+=getsum(1,cnt1,cnt1);
        printf("%lld\n",ans+getsum(1,1,cnt1)+getsum(3,1,cnt2));
    }
    return 0;
}
