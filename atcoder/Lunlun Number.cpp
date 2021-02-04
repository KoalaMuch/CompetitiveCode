#include<bits/stdc++.h>
using namespace std;
queue< long long > q;
vector< long long > lunlun;
map< long long,long long > mp;
int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=10;i++)  q.push(i),mp[i] = 1;
    int cnt = 0;
    while(!q.empty())
    {
        long long now = q.front();  q.pop();
        lunlun.push_back(now);
        long long nxt = now*10+(now%10);
//        printf("%lld %lld\n",now,nxt);
        if(nxt<=3234566667&&!mp[nxt])                 mp[nxt]=1,q.push(nxt);
        if(nxt-1<=3234566667&&now%10!=0&&!mp[nxt-1])  mp[nxt-1] = 1,q.push(nxt-1);
        if(nxt+1<=3234566667&&now%10!=9&&!mp[nxt+1])  mp[nxt+1] = 1,q.push(nxt+1);
    }
    sort(lunlun.begin(),lunlun.end());
//    printf("%d\n",lunlun.size());
    printf("%lld\n",lunlun[n-1]);
    return 0;
}
/*
3234566667

*/
