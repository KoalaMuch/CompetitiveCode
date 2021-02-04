/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int K = 105;
const int N = 205;
int up[K][N][N];
int lf[K][N][N];
int dp[N][N];
main ()
{
  int n, m, maxlvl, t;
  scanf ("%d %d %d %d", &n, &m, &maxlvl, &t);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      up[0][i][j] = lf[0][i][j] = -1e9;
  for (int i = 1; i <= maxlvl; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= m; k++)
	    scanf ("%d %d", &up[i][j][k], &lf[i][j][k]), up[i][j][k] = max (up[i - 1][j][k], up[i][j][k]), lf[i][j][k] = max (lf[i - 1][j][k], lf[i][j][k]);
  for (int i = 1; i <= n; i++)
    dp[i][0] = 1e9;
  for (int i = 1; i <= m; i++)
    dp[0][i] = 1e9;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
	{
	  int lim;
	  scanf ("%d", &lim);
	  if (i == 1 && j == 1) continue;
	  for (int k = 0; k <= min(lim,maxlvl-1); k++)
	  {
	      dp[i][j] = max (dp[i][j],min (dp[i - 1][j] + up[k+1][i][j], dp[i][j - 1] + lf[min(lim - k+1,maxlvl)][i][j]));
	  }
	}
  }
  printf (dp[n][m] <= t ? "Peatland is protected\n" : "Peatland is destroyed\n");
  if(dp[n][m]<=t)   printf("%d\n",dp[n][m]);
  else              printf("%d\n",dp[n][m]-t);
  return 0;
}
