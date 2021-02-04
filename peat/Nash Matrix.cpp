#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char ans[N][N];
int x[N][N];
int y[N][N];
queue< pair< int,int > > q;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d %d",&x[i][j],&y[i][j]);
        }
    }
    int ch = 0;
    for(int i=1;i<=n&&!ch;i++)
    {
        for(int j=1;j<=n&&!ch;j++)
        {
            if(isalpha(ans[i][j]))  continue;
            if(x[i][j]==-1)
            {
                if(x[i-1][j]==-1)   ans[i][j]='U';
                else if(x[i][j-1]==-1)   ans[i][j]='L';
                else if(x[i+1][j]==-1)
                {
                    ans[i][j]='D';
                    if(!isalpha(ans[i+1][j]))   ans[i+1][j]='U';
                }
                else if(x[i][j+1]==-1)
                {
                    ans[i][j]='R';
                    if(!isalnum(ans[i][j+1]))   ans[i][j+1]='L';
                }
                else ch = 1;
                continue;
            }
            else if(x[i][j]==i&&y[i][j]==j)
            {
                ans[i][j]='X';
                q.push({i,j});
                while(!q.empty())
                {
                    int ii = q.front().first,jj = q.front().second; q.pop();
                    if(!isalpha(ans[ii-1][jj])&&x[ii-1][jj]==x[ii][jj]&&y[ii-1][jj]==y[ii][jj]) ans[ii-1][jj]='D',q.push({ii-1,jj});
                    if(!isalpha(ans[ii+1][jj])&&x[ii+1][jj]==x[ii][jj]&&y[ii+1][jj]==y[ii][jj]) ans[ii+1][jj]='U',q.push({ii+1,jj});
                    if(!isalpha(ans[ii][jj-1])&&x[ii][jj-1]==x[ii][jj]&&y[ii][jj-1]==y[ii][jj]) ans[ii][jj-1]='R',q.push({ii,jj-1});
                    if(!isalpha(ans[ii][jj+1])&&x[ii][jj+1]==x[ii][jj]&&y[ii][jj+1]==y[ii][jj]) ans[ii][jj+1]='L',q.push({ii,jj+1});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   ch|=(!isalpha(ans[i][j]));
    if(ch)    return puts("INVALID"),0;
    printf("VALID\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
