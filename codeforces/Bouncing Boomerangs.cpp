#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector< int > col[N];
int a[N];
int main()
{
    int n,cur1 = 0,cur2 = 0,fb;
    bool ok = true;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            if(col[i].empty())  col[i].push_back(i);
        }
        else if(a[i]==2)
        {
            while(cur1<=i)  ++cur1;
            while(cur1<=n)
            {
                fb = i;
                if(col[i].size()==1)        fb = col[i][0];
                else if(col[i].size()==2)   fb = max(col[i][0],col[i][1]);
                if(a[cur1]==1&&col[cur1].empty())
                {
                    col[cur1].push_back(fb);
                    if(col[i].empty())  col[i].push_back(fb);
                    break;
                }
                ++cur1;
            }
            if(cur1==n+1)   {ok = false;break;}
        }
        else if(a[i]==3)
        {
            while(cur2<=i)  ++cur2;
            while(cur2<=n)
            {
                fb = i;
                if(col[i].size()==1)        fb = col[i][0];
                else if(col[i].size()==2)   fb = max(col[i][0],col[i][1]);
                if(a[cur2]!=0&&col[cur2].empty())
                {
                    col[cur2].push_back(fb);
                    col[cur2].push_back(cur2);
                    if(col[i].empty())  col[i].push_back(fb);
                    break;
                }
                ++cur2;
            }
            if(cur2==n+1)   {ok = false;break;}
        }
    }
    if(ok)
    {
        int ans = 0;
        for(int i=1;i<=n;i++)   ans+=(int)(col[i].size());
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
        {
            for(auto &x:col[i])
            {
                printf("%d %d\n",x,i);
            }
        }
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
