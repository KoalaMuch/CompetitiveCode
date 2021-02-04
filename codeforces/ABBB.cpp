#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
char s[N];
stack< int > st;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--)
    {
        int cnt = 0;
        scanf(" %s",s+1);
        n = strlen(s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='B'&&!st.empty())
            {
                ++cnt;
                st.pop();
            }
            else    st.push(s[i]);
        }
        printf("%d\n",st.size());
        while(!st.empty())  st.pop();
    }
    return 0;
}
