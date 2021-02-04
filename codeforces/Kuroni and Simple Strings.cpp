#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char str[N];
int mark[N];
vector< int > ans;
int main()
{
    int n;
    scanf(" %s",str+1);
    n = strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='(')
        {
            for(int j=n;j>=i+1;j--)
            {
                if(str[j]==')'&&!mark[j])
                {
                    mark[j] = 1;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
    }
    if(ans.empty()) printf("0\n");
    else
    {
        sort(ans.begin(),ans.end());
        printf("1\n%d\n",ans.size());
        for(auto &x:ans)    printf("%d ",x);
    }
    return 0;
}
