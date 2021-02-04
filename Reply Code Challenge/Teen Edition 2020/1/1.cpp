#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
struct A
{
    int score,ti,id;
    bool operator<(const A&o)const
    {
        if(score!=o.score)  return score>o.score;
        if(ti!=o.ti)    return ti<o.ti;
        return id<o.id;
    }
};
int sc[8] = {100,200,300,400,500};
int mark[N][7][7];
A a[N];
int main()
{
    freopen("in5.txt","r",stdin);
    freopen("out5.txt","w",stdout);
    int T,n,l,stmp,Tid,Pid,Iid,cor;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&l);
        for(int i=1;i<=n;i++)   a[i].id = i;
        for(int i=1;i<=l;i++)
        {
            scanf("%d %d %d %d %d",&stmp,&Tid,&Pid,&Iid,&cor);
            if(!cor)  continue;
            if(mark[Tid][Pid][Iid])   continue;
            a[Tid].score+=sc[Iid-1];
            mark[Tid][Pid][Iid] = 1;
            a[Tid].ti+=stmp;
        }
        sort(a+1,a+n+1);
        printf("Case #%d: ",t);
        for(int i=1;i<=n;i++)   printf("%d ",a[i].id);
        printf("\n");
        memset(mark,0,sizeof mark);
        memset(a,0,sizeof a);
    }
    return 0;
}
