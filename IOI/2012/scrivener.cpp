//#include "grader.cpp"
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct A
{
    int l,r;
    char C;
};
A sm[N*30];
int root[N];
int cur;
int n;
int len[N];
int opr;
int clone(int idx)  {sm[++cur] = sm[idx];return cur;}
int update(int l,int r,int idx,int now,char v)
{
    int newnode = clone(now);
    if(l==r)
    {
        sm[newnode].C = v;
        return newnode;
    }
    int mid = (l+r) >> 1;
    if(idx<=mid)    sm[newnode].l = update(l,mid,idx,sm[newnode].l,v);
    else            sm[newnode].r = update(mid+1,r,idx,sm[newnode].r,v);
    return newnode;
}
char query(int l,int r,int now,int idx)
{
    if(l==r)    return sm[now].C;
    int mid = (l+r) >> 1;
    if(idx<=mid)    return query(l,mid,sm[now].l,idx);
    return query(mid+1,r,sm[now].r,idx);
}
void Init() {}
void TypeLetter(char L) {
    ++opr;
    ++n;
    len[opr] = n;
    root[opr] = update(0,1000000,n-1,root[opr-1],L);
}
void UndoCommands(int U) {
    ++opr;
    len[opr] = n = len[max(0,opr-U-1)];
    root[opr] = root[max(0,opr-U-1)];
}
char GetLetter(int P) {
    return P>=n ? '\0' : query(0,1000000,root[opr],P);
}
/*
int main()
{
    while(1)
    {
        int cmd,U,P;
        char L;
        scanf("%d",&cmd);
        if(cmd==1)  scanf(" %c",&L),TypeLetter(L);
        else if(cmd==2) scanf("%d",&U),UndoCommands(U);
        else            scanf("%d",&P),printf("%c\n",GetLetter(P));
    }

}
1 a
1 b
3 1
1 d
2 2
2 1
3 2
1 e
2 1
2 5
1 c
3 2
2 2
3 2
*/
