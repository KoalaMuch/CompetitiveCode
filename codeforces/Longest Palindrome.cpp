#include<bits/stdc++.h>
using namespace std;
const int N = 55;
map< string,int > mp;
string s;
string ans;
string pl;
string tmp;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        mp[s] = 1;
        int ch = 0;
        for(int j=0;j<m;j++)
        {
            if(s[j]!=s[m-j-1])  ch = 1;
        }
        if(!ch) pl = s;
        else
        {
            reverse(s.begin(),s.end());
            if(mp[s])    for(int j=m-1;j>=0;j--)    ans+=s[j];
        }
    }
    tmp = ans;
    reverse(tmp.begin(),tmp.end());
    ans+=pl,ans+=tmp;
    cout << ans.size() << endl << ans << endl;
    return 0;
}
