#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&x,&y);
        int l = 1,r = n;
        while(l<r)
        {
            int mid = (l+r)>>1;
            int a = mid+1,c = mid+1;
            int b = n,d = n;
            if(x>=a)    --a;
            if(x>=b)    --b;
            if(y>=c)    --c;
            if(y>=d)    --d;
            if(min(a+d,b+c)<=x+y&&mid!=n)   l = mid+1;
            else                    r = mid;
        }
        printf("%d ",l);
        l = 1,r = n;
        while(l<r)
        {
            int mid = (l+r+1) >> 1;
            int a = 1,c = 1;
            int b = mid-1,d = mid-1;
            if(x<=a)    ++a;
            if(x<=b)    ++b;
            if(y<=c)    ++c;
            if(y<=d)    ++d;
            if(max(a+d,b+c)>x+y)   r = mid-1;
            else                    l = mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
