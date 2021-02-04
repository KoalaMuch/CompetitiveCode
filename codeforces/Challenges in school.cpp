#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
vector< pair< int,int > > turn[N];
int pos[N];
int found[N];
char s[N];
int main()
{
    int n,k,mn = 0,mx = 0;
    scanf("%d %d %s",&n,&k,s+1);
    for(int i=1,R=0;i<=n;i++)
    {
        pos[i] = i;
        int lst = 0;
        if(s[i]=='L')
        {
            for(int j=i-1;j>=1;j--)
            {
                if(s[j]=='R')
                {
                    ++mx;
                    ++found[j];
                    turn[max(lst+1,found[j])-1].push_back({j,i});
                    mn = max(mn,max(lst+1,found[j]));
                    lst = max(lst+1,found[j]);
                }
            }
        }
    }
    if(k>mx||k<mn)    return !printf("-1\n");
    for(int i=0;i<mn;i++)
    {
        int sz = turn[i].size();
        if(mn-i==k)
        {
            --k;
            printf("%d ",sz);
            for(auto &x:turn[i])    printf("%d ",pos[x.first]),swap(pos[x.first],pos[x.second]);
            printf("\n");
            continue;
        }
        for(int j=0;j<sz;j++)
        {
            if(k>mn-i)
            {
                --k;
                printf("1 %d\n",pos[turn[i][j].first]),swap(pos[turn[i][j].first],pos[turn[i][j].second]);
            }
            else if(mn-i==k)
            {
                int lft = sz-j;
                --k;
                printf("%d ",lft);
                for(int l=j;l<sz;l++)   printf("%d ",pos[turn[i][l].first]),swap(pos[turn[i][l].first],pos[turn[i][l].second]);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
/*
6 5
RRLLRL

6 6
RRLLRL
*/
