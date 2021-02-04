#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
vector< char > v;
vector< char > ans;
char s[N];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        int id = 1;
        scanf("%d %s",&n,s+1);
        ans.clear();
        for(int i=1;i<=n;i++)   ans.push_back(s[i]);
        for(int i=2;i<=n;i++)
        {
            v.clear();
            for(int j=i;j<=n;j++)   v.push_back(s[j]);
            if((n-i+1)%2)   for(int j=i-1;j>=1;j--) v.push_back(s[j]);
            else            for(int j=1;j<=i-1;j++) v.push_back(s[j]);
            if(v<ans)   ans = v,id = i;
        }
        for(auto &x:ans)    printf("%c",x);
        printf("\n%d\n",id);
    }
    return 0;
}
