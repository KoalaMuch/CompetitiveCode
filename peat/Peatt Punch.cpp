#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
stack< pair< int,int > > st;
int a[N];
int main()
{
    int n,q,h;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int mn = 1e9;
        scanf("%d",&h);
        while(!st.empty()&&st.top().second+st.top().first>=h)   mn = min(mn,st.top().second),st.pop();
        if(st.empty()) st.push({h,0});
        else           st.push({h,min(mn,max(st.top().second,h-st.top().first))});
        a[i] = st.top().second;
    }
    sort(a+1,a+n+1);
    while(q--)
    {
        scanf("%d",&h);
        printf("%d\n",n-(upper_bound(a+1,a+n+1,h)-a)+1);
    }
    return 0;
}
