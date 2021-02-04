#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector< int > factor[N];
map< int,int > mp1;
map< int,int > mp2;
long long dp[N];
int main()
{
    int n,num,ans = 1e9;
    scanf("%d",&n);
    for(int i=2;i<=1000000;i++)
    {
        if(factor[i].empty())
        {
            factor[i].push_back(i);
            for(int j=i;j<=1000000;j+=i)
            {
                if(factor[j].size()<=1) factor[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int cnt1 = 0,cnt2 = 0;
        scanf("%d",&num);
        if(num==1)  return printf("1\n"),0;
        if(factor[num].size()==1)
        {
            int a  = factor[num][0];
            while(num%a==0) ++cnt1,num/=a;
            if(cnt1%2==0)    return printf("1\n"),0;
            else            num = a;
        }
        else
        {
            int a = factor[num][0],b = factor[num][1];
            while(num%a==0) ++cnt1,num/=a;
            while(num%b==0) ++cnt2,num/=b;
            if(cnt1%2==0&&cnt2%2==0)    return printf("1\n"),0;
            else                        num = (cnt1%2)*a+(cnt2%2)*b;
        }
    }
    return 0;
}
/*
   1
2 3 5 7
6 10 35
*/
